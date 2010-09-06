xof 0303txt 0032
template Vector {
 <3d82ab5e-62da-11cf-ab39-0020af71e433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template MeshFace {
 <3d82ab5f-62da-11cf-ab39-0020af71e433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template Mesh {
 <3d82ab44-62da-11cf-ab39-0020af71e433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

template MeshNormals {
 <f6f23f43-7686-11cf-8f52-0040333594a3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template Coords2d {
 <f6f23f44-7686-11cf-8f52-0040333594a3>
 FLOAT u;
 FLOAT v;
}

template MeshTextureCoords {
 <f6f23f40-7686-11cf-8f52-0040333594a3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}


Mesh Plan01 {
 8;
 -645.12506;-145.125061;-645.12506;,
 -645.12512;-145.125122;645.12500;,
 645.12506;-145.125122;645.12500;,
 645.12506;-145.125061;-645.12506;,
 -645.12506;1145.12500;-645.12500;,
 -645.12506;1145.12500;645.12506;,
 645.12512;1145.12500;645.12506;,
 645.12506;1145.12500;-645.12506;;
 6;
 3;4,5,0;,
 3;1,0,5;,
 3;5,6,1;,
 3;2,1,6;,
 3;6,7,2;,
 3;3,2,7;;

 MeshNormals  {
  8;
  1.000000;-0.000000;0.000000;,
  0.707107;0.707107;-0.000000;,
  1.000000;-0.000000;-0.000000;,
  0.707107;0.707107;-0.000000;,
  -0.707107;0.707107;0.000000;,
  -0.707107;0.707107;0.000000;,
  -1.000000;-0.000000;0.000000;,
  -1.000000;-0.000000;0.000000;;
  6;
  3;0,1,2;,
  3;3,2,1;,
  3;1,4,3;,
  3;5,3,4;,
  3;4,6,5;,
  3;7,5,6;;
 }

 MeshTextureCoords  {
  8;
  -2.593640;3.593640;,
  -0.531213;3.593640;,
  1.531213;3.593640;,
  3.593639;3.593640;,
  -2.593640;-2.593639;,
  -0.531213;-2.593639;,
  1.531213;-2.593639;,
  3.593639;-2.593639;;
 }
}