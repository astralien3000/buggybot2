import bpy

def bone_matrix(bone):
    if bone.parent == None:
        return bone.matrix_local
    else:
        return bone.parent.matrix_local.inverted() * bone.matrix_local
    
    
def find(bone, func):
    func(bone)
    for b in bone.children:
        find(b, func)
        
def my_print(bone):
    print("using " + str(bone.name).replace(".00", "") + " = ")
    print("G::Matrix<4,4>::Any<")
    for row in bone_matrix(bone):
        for col in row:
            p = int(col*1024)
            q = int(1024)
            if(p%q == 0):
                print("  C<"+str(int(p/q))+">,")
            else:
                print("  Q<"+str(p)+","+str(q)+">,")
    print(">;")
                
            

find(bpy.data.armatures[0].bones[0], my_print)
