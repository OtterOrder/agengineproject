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


Mesh sponza_117 {
 7;
 -1428.51978;-2.506226;-574.02930;,
 -1428.51978;-2.506226;644.31140;,
 -63.342041;-2.506226;643.83643;,
 1302.19055;-2.506226;643.36169;,
 129.614685;-2.506226;-574.02954;,
 1302.19055;-2.506226;-574.02966;,
 -254.356689;-2.506226;-574.02942;;
 5;
 3;3,4,6;,
 3;4,3,5;,
 3;0,3,6;,
 3;3,0,2;,
 3;1,2,0;;

 MeshNormals  {
  2;
  0.000000;1.000000;0.000000;,
  0.000000;1.000000;0.000000;;
  5;
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;1,1,1;,
  3;0,0,0;;
 }

 MeshTextureCoords  {
  7;
  8.617465;-4.952472;,
  8.617465;-0.264228;,
  3.364184;-0.266055;,
  -1.890463;-0.267882;,
  2.621676;-4.952473;,
  -1.890463;-4.952473;,
  4.099219;-4.952473;;
 }
}