
src_dir='./linux'
dst_dir='../someTutorials-Linux/linux'

import os
import shutil
if os.path.exists(dst_dir):    
    shutil.rmtree(dst_dir)
else:
    print(" --  No such directory: ",dst_dir)

shutil.copytree(src_dir, dst_dir)



os.chdir('../someTutorials-Linux')
print(' -- pwd: ',os.getcwd())

os.system('git add .')
os.system('git commit -m "update"')
os.system('git push origin master:master')

# git add .
# git commit -m "update"
# git push origin main:main