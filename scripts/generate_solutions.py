"""
Updated 11/7/2024
* Heapcheck and memcheck added
"""
import subprocess
import sys
import yaml



def run_subprocess(cmd):
    """Run a subprocess and capture its output and return code."""
    with subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE) as p:
        output = p.stdout.read()
        error_output = p.stderr.read()
        returncode = p.poll()
        p.kill()
    return output, error_output, returncode

print("GENERATING SOLUTIONS")
# Load the YAML data from the file
with open('tests/tests.yml', 'r') as yaml_file:
    yaml_data = yaml.safe_load(yaml_file)

# Iterate through the test cases
for test_suite in yaml_data.get("suites", []):
    for test_case in test_suite.get("tests", []):
        
        cmd = test_case.get("command", [])
        stream = test_case.get("stream", "stdout")
        test_type = test_case.get("type", "output")
        if test_type == "regex":
            test_case["solution"] = test_case.get("solution", "")
            continue
        # Run the command and capture the program output
        std_output, error_output, returncode = run_subprocess(cmd)
        
        print("Command: ", cmd)
        if stream == "stderr" or test_type == "memcheck" or test_type == "heapcheck":
            output = error_output
        else:
            output = std_output

        if test_type == "returncode":
            if(returncode == None):
                output = "Program did not return a value"
            else:
                output = int(returncode)
  
        
        # Update the YAML with the program output as the solution
        if test_type == "memcheck" or test_type == "heapcheck":
            output = output.decode("utf-8", errors="ignore")
            # print(output)  # Print the entire Valgrind output for debugging

            # Initialize variables to hold the solution parts
            in_use_solution = None
            total_usage_solution = None

            # Check if the output contains the lines we need
            for line in output.splitlines():
                if "in use at exit:" in line:
                    # Extract the part after the colon for "in use at exit"
                    in_use_solution = line.split(':', 1)[1].strip()  # Get the part after the colon
                elif "total heap usage:" in line:
                    # Extract the part after the colon for "total heap usage"
                    total_usage_solution = line.split(':', 1)[1].strip()  # Get the part after the colon
            print(in_use_solution, total_usage_solution)
            # Set the solution to the expected output format
            if in_use_solution and total_usage_solution:
                # Combine both solutions for the final output
                print (f"In use at exit: {in_use_solution}, Total heap usage: {total_usage_solution}")
                b_output = f"In use at exit: {in_use_solution}, Total heap usage: {total_usage_solution}".encode("utf-8")
                b_output2 = f"Total heap usage: {total_usage_solution}".encode("utf-8")
                
            else:
                # Default solution if no relevant output is found
                b_output = "Valgrind error".encode("utf-8")
                b_output2 = "Valgrind error".encode("utf-8")
            if test_type == "heapcheck":
                test_case["solution"] = b_output2
            if test_type == "memcheck":
                test_case["solution"] = b_output
            print(test_case["solution"])
        else:
            # print(cmd, test_type, output)
            test_case["solution"] = output

# Save the updated YAML back to the file
with open('tests/tests.yml', 'w') as yaml_file:
    yaml.dump(yaml_data, yaml_file, default_flow_style=False)