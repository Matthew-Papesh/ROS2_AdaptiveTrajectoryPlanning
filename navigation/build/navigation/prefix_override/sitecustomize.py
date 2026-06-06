import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/matthew-papesh/dev_ws/src/navigation/install/navigation'
