
src_dir='./linux'
dst_dir='../someTutorials-Linux/linux'

import os
import shutil
if os.path.exists(dst_dir):    
    shutil.rmtree(dst_dir)
else:
    print(" --  No such directory: ",dst_dir)

shutil.copytree(src_dir, dst_dir)

# git add .
# git commit -m "update"
# git push origin master