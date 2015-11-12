import ctypes
import sys
import time

blender_viz_so = ctypes.cdll.LoadLibrary("libblender_viz.so")

argsType = ctypes.c_char_p * len(sys.argv)
argv = argsType()
argc = ctypes.c_int(len(sys.argv))
for i in range(0, len(sys.argv)):
    argv[i] = sys.argv[i]

blender_viz_so.init(argc, argv)

def test(data):
    data = data.split("#")
    name = data[0]
    data = data[1].split(",")
    print(name)
    print(data)

CallbackType = ctypes.CFUNCTYPE(None, ctypes.c_char_p)
blender_viz_so.set_callback.argtypes = [CallbackType]
blender_viz_so.set_callback(CallbackType(test))

while 1:
    time.sleep(0)
