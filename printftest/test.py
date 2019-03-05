import os
import signal
import subprocess
import time

# The os.setsid() is passed in the argument preexec_fn so
# it's run after the fork() and before  exec() to run the shell.
with open(os.devnull, 'w') as devnull:
	cmd = 'docker build -t test-printf .'
	pro = subprocess.Popen(cmd, stdout=subprocess.PIPE, 
                       shell=True, preexec_fn=os.setsid) 
	time.sleep(2)
	output, errors = pro.communicate()
	#os.killpg(os.getpgid(pro.pid), signal.SIGTERM)
	
	cmd = 'docker run --network=mynetwork --rm --name my-running-app test-printf'
	pro = subprocess.Popen(cmd, stdout=subprocess.PIPE, 
	                       shell=True, preexec_fn=os.setsid, stderr=devnull) 
	
	time.sleep(5)
	output, errors = pro.communicate()
	print output
	#os.kil	lpg(os.getpgid(pro.pid), signal.SIGTERM)
