import bpy
import config
import mesh_generator as mg

bot = config.Robot
scn = bpy.data.scenes[0]
mg.create_shoulder(bot, scn, 'test')
