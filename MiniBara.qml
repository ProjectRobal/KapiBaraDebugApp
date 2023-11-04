import QtQuick
import QtQuick3D

Node {
    id: node

    // Resources
    PrincipledMaterial {
        id: material_002_material
        baseColor: "#ffcc2700"
        roughness: 1
        indexOfRefraction: 1.4500000476837158
    }
    PrincipledMaterial {
        id: material_003_material
        baseColor: "#fff1deff"
        roughness: 1
        indexOfRefraction: 1.4500000476837158
    }
    PrincipledMaterial {
        id: material_004_material
        baseColor: "#ff000000"
        roughness: 1
        indexOfRefraction: 1.4500000476837158
    }

    // Nodes:
    Node {
        id: miniBara_obj
        Model {
            id: miniBara
            source: "meshes/miniBara_mesh.mesh"
            materials: [
                material_002_material,
                material_003_material,
                material_004_material
            ]
        }
    }

    // Animations:
}
