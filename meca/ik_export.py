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
      
def real2cas(value):
    ret  = "CAS::General<double, double>::"
    p = int(value*1024)
    q = int(1024)
    if(p%q == 0):
        ret += "C<"+str(int(p/q))+">"
    else:
        ret += "Q<"+str(p)+","+str(q)+">"
    return ret

def matrix2cas(mat):
    vals = []
    for row in mat:
        for case in row:
            vals += [real2cas(case)]
    ret  = "CAS::General<double, double>::"
    ret += "Matrix<4,4>::"
    ret += "Any<"
    ret += ','.join(vals)
    ret += ">"
    return ret;

def name2cxx(name):
    return str(name).replace(".", "_")

def print_bone(bone):
    print("struct " + name2cxx(bone.name) + " {")
    if bone.parent != None:
        print("using parent = " + name2cxx(bone.parent.name) + ";")
    else:
        print("using parent = void;")
    mat  = "using matrix = "
    mat += matrix2cas(bone_matrix(bone)) + ";"
    print(mat)
    print("};")

def print_armature(armature):
    print("namespace " + name2cxx(armature.name) + " {")
    for b in armature.bones:
        print_bone(b)
    print("}")

for a in bpy.data.armatures:
    print_armature(a)
    
#for o in bpy.data.objects:
#    if(o.pose != None):
#        for b in o.pose.bones:
#            print(b.name)