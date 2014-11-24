import bpy

def create_shoulder(robot, scene, name):
    mesh = bpy.data.meshes.new(name+'_mesh')
    obj = bpy.data.objects.new(name+'_obj', mesh)
    scene.objects.link(obj)
    verts = []
    verts.append([2*robot.L3, robot.L4, robot.L5])
    verts.append([2*robot.L3, -robot.L4, robot.L5])
    verts.append([2*robot.L3, -robot.L4, -robot.L5])
    verts.append([2*robot.L3, robot.L4, -robot.L5])
    verts.append([0, robot.L4, robot.L5])
    verts.append([0, -robot.L4, robot.L5])
    verts.append([0, -robot.L4, -robot.L5])
    verts.append([0, robot.L4, -robot.L5])
    polys = []
    polys.append([0,1,2,3])
    polys.append([4,5,6,7])
    polys.append([1,2,6,5])
    polys.append([0,3,7,4])
    polys.append([0,1,5,4])
    polys.append([2,3,7,6])
    mesh.from_pydata(verts, [], polys)

