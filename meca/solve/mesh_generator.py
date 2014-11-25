import bpy

def create_box(range_x, range_y, range_z):
    verts = []
    verts.append([range_x[1], range_y[1], range_z[1]])
    verts.append([range_x[1], range_y[0], range_z[1]])
    verts.append([range_x[1], range_y[0], range_z[0]])
    verts.append([range_x[1], range_y[1], range_z[0]])
    verts.append([range_x[0], range_y[1], range_z[1]])
    verts.append([range_x[0], range_y[0], range_z[1]])
    verts.append([range_x[0], range_y[0], range_z[0]])
    verts.append([range_x[0], range_y[1], range_z[0]])
    polys = []
    polys.append([0,1,2,3])
    polys.append([4,5,6,7])
    polys.append([1,2,6,5])
    polys.append([0,3,7,4])
    polys.append([0,1,5,4])
    polys.append([2,3,7,6])
    return [verts,[],polys]

def create_obj(scene, pydata, name):
    mesh = bpy.data.meshes.new(name+'_mesh')
    obj = bpy.data.objects.new(name+'_obj', mesh)
    scene.objects.link(obj)
    mesh.from_pydata(pydata[0], pydata[1], pydata[2])
    return obj

def create_shoulder(robot, scene, name):
    xr = [0, 2*robot.L3]
    yr = [-robot.L4, robot.L4]
    zr = [-robot.L5, robot.L5]
    return create_obj(scene, create_box(xr, yr, zr), name)

def create_arm(robot, scene, name):
    xr = [0, robot.L6]
    yr = [-0.01, 0.01]
    zr = [-robot.L7, 0]
    return create_obj(scene, create_box(xr, yr, zr), name)

def create_forearm(robot, scene, name):
    xr = [0, robot.L6]
    yr = [-0.01, 0.01]
    zr = [-robot.L8, 0]
    return create_obj(scene, create_box(xr, yr, zr), name)
