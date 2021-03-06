// This file was created by Filewrap 1.2
// Little endian mode
// DO NOT EDIT

#include "../PVRTMemoryFileSystem.h"

// using 32 bit to guarantee alignment.
#ifndef A32BIT
 #define A32BIT static const unsigned int
#endif

// ******** Start: effect.pfx ********

// File data
static const char _effect_pfx[] = 
	"[HEADER]\r\n"
	"\tVERSION\t\t01.00.00.00\r\n"
	"\tDESCRIPTION OGLES3DeferredShading\r\n"
	"\tCOPYRIGHT\tImagination Technologies\r\n"
	"[/HEADER]\r\n"
	"\r\n"
	"///////////////////////////////////////////////////////////////////////////\r\n"
	"////                                                                   ////\r\n"
	"////                   GBUFFER RENDER                                  ////\r\n"
	"////                                                                   ////\r\n"
	"///////////////////////////////////////////////////////////////////////////\r\n"
	"\r\n"
	"//\r\n"
	"// Effect to render the scene using a cube shadow map\r\n"
	"//\r\n"
	"[EFFECT] \r\n"
	"\tNAME \tRenderGBuffer\r\n"
	"\t\t\r\n"
	"\t// GLOBALS UNIFORMS\r\n"
	"\tUNIFORM uWorldViewProjMatrix\tWORLDVIEWPROJECTION\r\n"
	"\tUNIFORM uWorldViewMatrix\t\tWORLDVIEW\r\n"
	"\tUNIFORM uViewProjMatrix\t\t\tVIEWPROJECTION\r\n"
	"\tUNIFORM uViewMatrix\t\t\t\tVIEW\r\n"
	"\tUNIFORM uWorldViewIT\t\t \tWORLDVIEWIT\r\n"
	"\t\t\r\n"
	"\tUNIFORM sTexture\t\t\t\tTEXTURE0\r\n"
	"\tUNIFORM sBumpMap\t\t\t\tTEXTURE1\r\n"
	"\t\r\n"
	"\t// ATTRIBUTES\r\n"
	"\tATTRIBUTE inVertex\t\t\t\tPOSITION\r\n"
	"\tATTRIBUTE\tinNormal\t\t\tNORMAL\r\n"
	"\tATTRIBUTE\tinTexCoord\t\t\tUV\r\n"
	"\tATTRIBUTE\tinTangent\t\t\tTANGENT\r\n"
	"\tATTRIBUTE\tinBoneIndex\t\t\tBONEINDEX\r\n"
	"\tATTRIBUTE\tinBoneWeights\t\tBONEWEIGHT\r\n"
	"\t\r\n"
	"\t// CUSTOM SEMANTICS\r\n"
	"\tUNIFORM uFarClipDistance\t\t\tCUSTOMSEMANTIC_FARCLIPDISTANCE\r\n"
	"\t\t\r\n"
	"\tUNIFORM uSpecularPower\t\t\t\tCUSTOMSEMANTIC_SPECULARPOWER\r\n"
	"\tUNIFORM uDiffuseColour\t\t\t\tCUSTOMSEMANTIC_DIFFUSECOLOUR\r\n"
	"\t\t\r\n"
	"\t// SHADERS\r\n"
	"\tVERTEXSHADER   GBufferVertexShader\r\n"
	"\tFRAGMENTSHADER GBufferFragmentShader\r\n"
	"[/EFFECT]\r\n"
	"\r\n"
	"[VERTEXSHADER]\r\n"
	"\tNAME \t\tGBufferVertexShader\r\n"
	"\r\n"
	"\t[GLSL_CODE]\r\n"
	"\t\t#version 300 es\r\n"
	"\r\n"
	"\t\t#define VERTEX_ARRAY      0\r\n"
	"\t\t#define NORMAL_ARRAY      1\r\n"
	"\t\t#define TEXCOORD_ARRAY    2\r\n"
	"\t\t#define TANGENT_ARRAY     3\r\n"
	"\t\t#define BONEINDEX_ARRAY   4\r\n"
	"\t\t#define BONEWEIGHT_ARRAY  5\r\n"
	"\t\t\r\n"
	"\t\tlayout(location = VERTEX_ARRAY)   in highp   vec3 inVertex;\r\n"
	"\t\tlayout(location = NORMAL_ARRAY)   in highp   vec3 inNormal;\r\n"
	"\t\tlayout(location = TEXCOORD_ARRAY) in mediump vec2 inTexCoord;\r\n"
	"\t\tlayout(location = TANGENT_ARRAY)  in highp   vec3 inTangent;\r\n"
	"\r\n"
	"\t\tuniform  mat4  uWorldViewProjMatrix; \r\n"
	"\t\tuniform  mat4  uWorldViewMatrix; \r\n"
	"\t\tuniform  mat4  uViewProjMatrix;\r\n"
	"\t\tuniform  mat4  uViewMatrix;\r\n"
	"\t\tuniform  mat3  uWorldViewIT; \r\n"
	"\r\n"
	"\t\tout  mediump  vec2   vTexCoord;\r\n"
	"\t\tout  highp    vec3   vNormal;\r\n"
	"\t\tout  highp    vec3   vTangent;\r\n"
	"\t\tout  highp    vec3   vBinormal;\r\n"
	"\t\tout  highp    vec3   vViewPos;\r\n"
	"\r\n"
	"\t\tvoid main() \r\n"
	"\t\t{\r\n"
	"\t\t\tgl_Position = uWorldViewProjMatrix * vec4(inVertex, 1.0);\r\n"
	"\t  \r\n"
	"\t\t\t// Transform normal from model space to eye space\r\n"
	"\t\t\tvNormal = uWorldViewIT * inNormal;\r\n"
	"\t\t\tvTangent = uWorldViewIT * inTangent;\r\n"
	"\t\t\tvBinormal = cross(vNormal, vTangent);\r\n"
	"\t  \r\n"
	"\t\t\t// Pass the vertex position in view space for depth calculations\r\n"
	"\t\t\tvViewPos = (uWorldViewMatrix * vec4(inVertex, 1.0)).xyz;\r\n"
	"\t\r\n"
	"\t\t\t// Pass the texture coordinates to the fragment shader\r\n"
	"\t\t\tvTexCoord = inTexCoord;\t\t\t\t\r\n"
	"\t\t}\r\n"
	"\t[/GLSL_CODE]\r\n"
	"[/VERTEXSHADER]\r\n"
	" \r\n"
	"[FRAGMENTSHADER] \r\n"
	"\tNAME \t\tGBufferFragmentShader \r\n"
	"\r\n"
	"\t[GLSL_CODE]\r\n"
	"\t\t#version 300 es\r\n"
	"\r\n"
	"\t\tuniform  sampler2D  sTexture;\r\n"
	"\t\tuniform  sampler2D  sBumpMap;\r\n"
	"\r\n"
	"\t\tuniform  highp float  uFarClipDistance;\r\n"
	"\t\tuniform  lowp  float  uSpecularPower;\r\n"
	"\t\tuniform  lowp  vec3   uDiffuseColour;\r\n"
	"\r\n"
	"\t\tin  mediump vec2   vTexCoord;\r\n"
	"\t\tin  highp   vec3   vNormal;\r\n"
	"\t\tin  highp   vec3   vTangent;\r\n"
	"\t\tin  highp   vec3   vBinormal;\r\n"
	"\t\tin  highp   vec3   vViewPos;\r\n"
	"\t\t\r\n"
	"\t\tlayout(location = 0) out lowp  vec4  oAlbedo; \r\n"
	"\t\tlayout(location = 1) out highp vec3  oNormal; \r\n"
	"\t\tlayout(location = 2) out highp vec4  oDepth; \r\n"
	"\r\n"
	"\t\tvoid main() \r\n"
	"\t\t{\r\n"
	"\t\t\t// Calculate the albedo\r\n"
	"\t\t\tlowp vec3 albedo = texture(sTexture, vTexCoord).rgb * uDiffuseColour;\r\n"
	"\t\t\t// Pack the specular exponent with the albedo\r\n"
	"\t\t\toAlbedo = vec4(albedo, uSpecularPower);\r\n"
	"\r\n"
	"\t\t\t// Calculate viewspace perturbed normal\r\n"
	"\t\t\thighp vec3 bumpmap = normalize(texture(sBumpMap, vTexCoord).rgb * 2.0 - 1.0);\r\n"
	"\t\t\thighp mat3 tangentSpace = mat3(normalize(vTangent), normalize(vBinormal), normalize(vNormal));\t\r\n"
	"\t\t\thighp vec3 normalVS = tangentSpace * bumpmap;\t\t\r\n"
	"\r\n"
	"\t\t\t// Scale the normal range from [-1,1] to [0, 1] to pack it into the RGB_U8 texture\r\n"
	"\t\t\toNormal.xyz = normalVS * 0.5 + 0.5;\t\r\n"
	"\r\n"
	"\t\t\t// Pack the depth value into 4 channels \t\r\n"
	"\t\t\t// Pack the depth value into 4 channels \t\r\n"
	"\t\t\thighp float scaledDepth = length(vViewPos) / uFarClipDistance;\r\n"
	"\t\t\thighp vec4 enc = vec4(1.0, 255.0, 65025.0, 160581375.0) * scaledDepth;\r\n"
	"\t\t\tenc = fract(enc);\r\n"
	"\t\t\tenc -= enc.yzww * vec4(1.0/255.0,1.0/255.0,1.0/255.0,0.0);\t\t\t\r\n"
	"\t\t\t\r\n"
	"\t\t\toDepth = enc;\t\t\t\r\n"
	"\t\t}\r\n"
	"\t[/GLSL_CODE]\r\n"
	"[/FRAGMENTSHADER]\r\n"
	"\r\n"
	"\r\n"
	"\r\n"
	"///////////////////////////////////////////////////////////////////////////\r\n"
	"////                                                                   ////\r\n"
	"////                   DEFERRED LIGHT SHADERS                          ////\r\n"
	"////                                                                   ////\r\n"
	"///////////////////////////////////////////////////////////////////////////\r\n"
	"\r\n"
	"// \r\n"
	"// Vertex shader that is shared amongst (most) deferred light shaders\r\n"
	"//\r\n"
	"[VERTEXSHADER]\r\n"
	"\tNAME \t\tDeferredVertexShader\r\n"
	"\r\n"
	"\t[GLSL_CODE]\r\n"
	"\t\t#version 300 es\r\n"
	"\r\n"
	"\t\t#define VERTEX_ARRAY      0\r\n"
	"\r\n"
	"\t\tlayout(location = VERTEX_ARRAY)   in highp   vec3 inVertex;\r\n"
	"\r\n"
	"\t\tuniform  mat4  uWorldViewProjMatrix;\r\n"
	"\t\tuniform  mat4  uWorldViewMatrix;\r\n"
	"\t\t\r\n"
	"\t\tout  highp   vec3  vPositionVS;\r\n"
	"\t\tout  highp   vec3  vViewDirVS;\r\n"
	"\t\tout  mediump vec2  vTexCoord;\r\n"
	"\r\n"
	"\t\tvoid main() \r\n"
	"\t\t{ \t\r\n"
	"\t\t\tgl_Position = uWorldViewProjMatrix * vec4(inVertex, 1.0);\r\n"
	"\t\t\tgl_Position.xyz = gl_Position.xyz / gl_Position.w;\r\n"
	"\t\t\tgl_Position.w = 1.0;\r\n"
	"\t\t\t\r\n"
	"\t\t\tvTexCoord = (gl_Position.xy + 1.0) * 0.5;\r\n"
	"\t\r\n"
	"\t\t\t// Calculate the view-space position for lighting calculations\r\n"
	"\t\t\tvPositionVS = (uWorldViewMatrix * vec4(inVertex, 1.0)).xyz;\r\n"
	"\r\n"
	"\t\t\t// Pass the view direction\r\n"
	"\t\t\tvViewDirVS = vPositionVS;\r\n"
	"\t\t} \r\n"
	"\t[/GLSL_CODE]\r\n"
	"[/VERTEXSHADER]\r\n"
	"\r\n"
	"//\r\n"
	"// Calculates the lighting for a point light source\r\n"
	"//\r\n"
	"[EFFECT] \r\n"
	"\tNAME \tRenderPointLight\r\n"
	"\t\t\r\n"
	"\t// GLOBALS UNIFORMS\r\n"
	"\tUNIFORM uWorldViewProjMatrix\t\tWORLDVIEWPROJECTION\r\n"
	"\tUNIFORM uWorldViewMatrix\t\t\tWORLDVIEW\r\n"
	"\tUNIFORM uWorldIT\t\t\t\t\tWORLDIT\r\n"
	"\tUNIFORM uLightColourIntensity\t\tLIGHTCOLOR\r\n"
	"\t\t\r\n"
	"\tUNIFORM sAlbedo\t\t\t\t\t\tTEXTURE0\r\n"
	"\tUNIFORM sNormals\t\t\t\t\tTEXTURE1\r\n"
	"\tUNIFORM sDepth\t\t\t\t\t\tTEXTURE2\r\n"
	"\tUNIFORM sLightEnvMap\t\t\t\tTEXTURE3\r\n"
	"\t\r\n"
	"\t// CUSTOM SEMANTICS\r\n"
	"\tUNIFORM uFarClipDistance\t\t\tCUSTOMSEMANTIC_FARCLIPDISTANCE\r\n"
	"\t\r\n"
	"\tUNIFORM uLightViewPosition\t\tCUSTOMSEMANTIC_POINTLIGHT_VIEWPOSITION\r\n"
	"\t\r\n"
	"\t// ATTRIBUTES\r\n"
	"\tATTRIBUTE inVertex\t\t\tPOSITION\r\n"
	"\r\n"
	"\t// SHADERS\t\r\n"
	"\tVERTEXSHADER   DeferredVertexShader\r\n"
	"\tFRAGMENTSHADER PointLightFragmentShader\r\n"
	"[/EFFECT]\r\n"
	"\r\n"
	"[FRAGMENTSHADER] \r\n"
	"\tNAME \t\tPointLightFragmentShader \r\n"
	"\r\n"
	"\t[GLSL_CODE]\r\n"
	"\t\t#version 300 es\r\n"
	"\r\n"
	"\t\tuniform  sampler2D    sAlbedo;\r\n"
	"\t\tuniform  sampler2D    sNormals;\r\n"
	"\t\tuniform  sampler2D    sDepth;\r\n"
	"\t\tuniform  samplerCube  sLightEnvMap;\r\n"
	"\r\n"
	"\t\tuniform  highp float  uFarClipDistance;\r\n"
	"\t\tuniform  highp vec3   uLightColourIntensity;\r\n"
	"\r\n"
	"\t\tuniform  highp mat3   uWorldIT;\t\t\r\n"
	"\t\tuniform  highp vec3   uLightViewPosition;\r\n"
	"\t\t\r\n"
	"\t\tin  highp   vec3  vPositionVS;\r\n"
	"\t\tin  highp   vec3  vViewDirVS;\r\n"
	"\t\tin  mediump vec2  vTexCoord;\r\n"
	"\r\n"
	"\t\tlayout(location = 0) out lowp vec4 oColour;\r\n"
	"\r\n"
	"\t\tvoid main()\r\n"
	"\t\t{\r\n"
	"\t\t\t//\r\n"
	"\t\t\t// Read GBuffer attributes\r\n"
	"\t\t\t//\t\r\n"
	"\t\t\thighp vec4 depthTex = texture(sDepth, vTexCoord);\r\n"
	"\t\t\thighp vec4 albedoSpec = texture(sAlbedo, vTexCoord);\r\n"
	"\t\t\thighp vec3 normalTex = texture(sNormals, vTexCoord).xyz;\r\n"
	"\t\t\t\r\n"
	"\t\t\t// reconstruct original depth value\r\n"
	"\t\t\thighp float depth = dot(depthTex, vec4(1.0, 1.0/255.0, 1.0/65025.0, 1.0/160581375.0));\r\n"
	"\r\n"
	"\t\t\t//\r\n"
	"\t\t\t// Reconstruct common vectors and world space position \r\n"
	"\t\t\t//\r\n"
	"\t\t\thighp vec3 positionVS = normalize(vPositionVS) * depth * uFarClipDistance;\t\r\n"
	"\t\t\thighp vec3 lightDirection = uLightViewPosition - positionVS;\r\n"
	"\t\t\tlowp  vec3 lightColour = texture(sLightEnvMap, uWorldIT * lightDirection).rgb;\r\n"
	"\t\t\thighp float invLightDistance = 1.0 / length(lightDirection);\r\n"
	"\t\t\tlightDirection *= invLightDistance;\r\n"
	"\t\r\n"
	"\t\t\t//\r\n"
	"\t\t\t// Calculate lighting terms\r\n"
	"\t\t\t//\r\n"
	"\t\t\thighp vec3 normal = normalize(normalTex * 2.0 - 1.0);\t\r\n"
	"\t\t\thighp float n_dot_l = max(dot(lightDirection, normal), 0.0);\t\r\n"
	"\t\t\thighp vec3 diffuse = n_dot_l * albedoSpec.rgb;\r\n"
	"\r\n"
	"\t\t\thighp vec3 viewDirection = normalize(vViewDirVS);\r\n"
	"\t\t\thighp vec3 reflectedLightDirection = reflect(lightDirection, normal);\r\n"
	"\t\t\thighp float v_dot_r = max(dot(viewDirection, reflectedLightDirection), 0.0);\r\n"
	"\t\t\tdiffuse += vec3(pow(v_dot_r, albedoSpec.a * 100.0));\r\n"
	"\t\r\n"
	"\t\t\thighp float attenuation = invLightDistance * invLightDistance;\r\n"
	"\t\t\toColour = vec4(diffuse * uLightColourIntensity * attenuation * lightColour, 1.0);\r\n"
	"\t\t}\r\n"
	"\t[/GLSL_CODE]\r\n"
	"[/FRAGMENTSHADER]\r\n"
	"\r\n"
	"//\r\n"
	"// Calculates the lighting for a directional light source\r\n"
	"//\r\n"
	"[EFFECT] \r\n"
	"\tNAME \tRenderDirectionalLight\r\n"
	"\t\t\r\n"
	"\t// GLOBALS UNIFORMS\r\n"
	"\tUNIFORM uLightColourIntensity\t\tLIGHTCOLOR\r\n"
	"\t\t\t\r\n"
	"\tUNIFORM sAlbedo\t\t\t\t\t\tTEXTURE0\r\n"
	"\tUNIFORM sNormals\t\t\t\t\tTEXTURE1\r\n"
	"\t\t\r\n"
	"\t// CUSTOM SEMANTICS\r\n"
	"\tUNIFORM uLightDirection\t\t\tCUSTOMSEMANTIC_DIRECTIONALLIGHT_DIRECTION\r\n"
	"\t\r\n"
	"\t// ATTRIBUTES\r\n"
	"\tATTRIBUTE inVertex\t\t\tPOSITION\r\n"
	"\tATTRIBUTE inTexCoord\t\t\tUV\r\n"
	"\r\n"
	"\t// SHADERS\t\r\n"
	"\tVERTEXSHADER   DirectionalLightVertexShader\r\n"
	"\tFRAGMENTSHADER DirectionalLightFragmentShader\r\n"
	"[/EFFECT]\r\n"
	"\r\n"
	"[VERTEXSHADER]\r\n"
	"\tNAME \t\tDirectionalLightVertexShader\r\n"
	"\r\n"
	"\t[GLSL_CODE]\r\n"
	"\t\t#version 300 es\r\n"
	"\r\n"
	"\t\t#define VERTEX_ARRAY      0\r\n"
	"\t\t#define NORMAL_ARRAY      1\r\n"
	"\t\t#define TEXCOORD_ARRAY    2\r\n"
	"\r\n"
	"\t\tlayout(location = VERTEX_ARRAY)   in highp   vec3 inVertex;\r\n"
	"\t\tlayout(location = TEXCOORD_ARRAY) in mediump vec2 inTexCoord;\r\n"
	"\r\n"
	"\t\tuniform  highp vec4  uLightDirection;\r\n"
	"\r\n"
	"\t\tout  highp   vec3  vLightDirection;\r\n"
	"\t\tout  mediump vec2  vTexCoord;\r\n"
	"\r\n"
	"\t\tvoid main() \r\n"
	"\t\t{ \t\r\n"
	"\t\t\tgl_Position = vec4(inVertex, 1.0);\r\n"
	"\r\n"
	"\t\t\tvTexCoord = inTexCoord;\r\n"
	"\t\t\tvLightDirection = uLightDirection.xyz;\r\n"
	"\t\t} \r\n"
	"\t[/GLSL_CODE]\r\n"
	"[/VERTEXSHADER]\r\n"
	"\r\n"
	"[FRAGMENTSHADER] \r\n"
	"\tNAME \t\tDirectionalLightFragmentShader \r\n"
	"\r\n"
	"\t[GLSL_CODE]\r\n"
	"\t\t#version 300 es\r\n"
	"\r\n"
	"\t\tuniform  sampler2D  sAlbedo;\r\n"
	"\t\tuniform  sampler2D  sNormals;\r\n"
	"\r\n"
	"\t\tuniform highp vec3  uLightColourIntensity;\r\n"
	"\r\n"
	"\t\tin highp   vec3 vLightDirection;\r\n"
	"\t\tin mediump vec2 vTexCoord;\r\n"
	"\r\n"
	"\t\tlayout(location = 0) out lowp vec4 oColour;\r\n"
	"\r\n"
	"\t\tvoid main()\r\n"
	"\t\t{\r\n"
	"\t\t\t// Fetch required gbuffer attributes\r\n"
	"\t\t\tlowp  vec3 albedo = texture(sAlbedo, vTexCoord).rgb;\r\n"
	"\t\t\thighp vec3 normalTex = texture(sNormals, vTexCoord).xyz;\r\n"
	"\t\t\thighp vec3 normal = normalize(normalTex.xyz * 2.0 - 1.0);\r\n"
	"\t\t\t\r\n"
	"\t\t\t// Calculate simple diffuse lighting\r\n"
	"\t\t\thighp float n_dot_l = max(dot(-vLightDirection, normal.xyz), 0.0);\r\n"
	"\t\t\tlowp vec3 colour = albedo * n_dot_l * uLightColourIntensity;\r\n"
	"\t\t\t\r\n"
	"\t\t\toColour = vec4(colour, 1.0);\r\n"
	"\t\t}\r\n"
	"\t[/GLSL_CODE]\r\n"
	"[/FRAGMENTSHADER]\r\n"
	"\r\n"
	"///////////////////////////////////////////////////////////////////////////\r\n"
	"////                                                                   ////\r\n"
	"////                   AUXILIARY SHADERS                               ////\r\n"
	"////                                                                   ////\r\n"
	"///////////////////////////////////////////////////////////////////////////\r\n"
	"\r\n"
	"//\r\n"
	"// Renders the geometry using a texture\r\n"
	"//\r\n"
	"[EFFECT] \r\n"
	"\tNAME \tRenderSimpleTexture\r\n"
	"\t\t\r\n"
	"\t// GLOBALS UNIFORMS\r\n"
	"\tUNIFORM uWorldViewProjMatrix\t\tWORLDVIEWPROJECTION\r\n"
	"\t\r\n"
	"\tUNIFORM sTexture\t\t\t\t\tTEXTURE0\r\n"
	"\t\r\n"
	"\t// ATTRIBUTES\r\n"
	"\tATTRIBUTE inVertex\t\t\t\t\tPOSITION\r\n"
	"\tATTRIBUTE\tinTexCoord\t\t\t\tUV\t\r\n"
	"\r\n"
	"\t// SHADERS\t\r\n"
	"\tVERTEXSHADER   VertexShader\r\n"
	"\tFRAGMENTSHADER TextureFragmentShader\r\n"
	"[/EFFECT]\r\n"
	"\r\n"
	"[FRAGMENTSHADER] \r\n"
	"\tNAME \t\tTextureFragmentShader \r\n"
	"\r\n"
	"\t[GLSL_CODE]\r\n"
	"\t\t#version 300 es\r\n"
	"\r\n"
	"\t\tuniform sampler2D sTexture;\r\n"
	"\t\tin mediump vec2 vTexCoord;\r\n"
	"\r\n"
	"\t\tlayout(location = 0) out lowp vec4 oColour;\r\n"
	"\r\n"
	"\t\tvoid main()\r\n"
	"\t\t{\r\n"
	"\t\t\toColour = texture(sTexture, vTexCoord);\t\t\t\r\n"
	"\t\t}\r\n"
	"\t[/GLSL_CODE]\r\n"
	"[/FRAGMENTSHADER]\r\n"
	"\r\n"
	"\r\n"
	"//\r\n"
	"// Renders the geometry using a single channel depth map, \r\n"
	"// scaling the depth values for visualization purposes.\r\n"
	"//\r\n"
	"[EFFECT] \r\n"
	"\tNAME \tRenderDepthTexture\r\n"
	"\t\t\r\n"
	"\t// GLOBALS UNIFORMS\r\n"
	"\tUNIFORM uWorldViewProjMatrix\tWORLDVIEWPROJECTION\r\n"
	"\t\r\n"
	"\tUNIFORM sTexture\t\t\t\tTEXTURE0\r\n"
	"\t\r\n"
	"\t// ATTRIBUTES\r\n"
	"\tATTRIBUTE\tinVertex\t\t\tPOSITION\r\n"
	"\tATTRIBUTE\tinTexCoord\t\t\tUV\t\r\n"
	"\r\n"
	"\t// SHADERS\t\r\n"
	"\tVERTEXSHADER   VertexShader\r\n"
	"\tFRAGMENTSHADER DepthTextureFragmentShader\r\n"
	"[/EFFECT]\r\n"
	"\r\n"
	"[FRAGMENTSHADER] \r\n"
	"\tNAME \t\tDepthTextureFragmentShader \r\n"
	"\r\n"
	"\t[GLSL_CODE]\r\n"
	"\t#version 300 es\r\n"
	"\r\n"
	"\t\tuniform sampler2D sTexture;\r\n"
	"\t\tin mediump vec2 vTexCoord;\r\n"
	"\r\n"
	"\t\tlayout(location = 0) out lowp vec4 oColour;\r\n"
	"\r\n"
	"\t\tvoid main()\r\n"
	"\t\t{\r\n"
	"\t\t\thighp vec4 depthTex = texture(sTexture, vTexCoord);\r\n"
	"\t\t\t\r\n"
	"\t\t\t// reconstruct original depth value\r\n"
	"\t\t\thighp float depth = dot(depthTex, vec4(1.0, 1.0/255.0, 1.0/65025.0, 1.0/160581375.0));\r\n"
	"\t\t\t\r\n"
	"\t\t\toColour = vec4(vec3(texture(sTexture, vTexCoord).r * 5.0), 1.0);\r\n"
	"\t\t\t\r\n"
	"\t\t}\r\n"
	"\t[/GLSL_CODE]\r\n"
	"[/FRAGMENTSHADER]\r\n"
	"\r\n"
	"\r\n"
	"//\r\n"
	"// Renders the geometry using a single colour passed as an uniform.\r\n"
	"//\r\n"
	"[EFFECT] \r\n"
	"\tNAME \tRenderSolidColour\r\n"
	"\t\t\r\n"
	"\t// GLOBALS UNIFORMS\r\n"
	"\tUNIFORM uWorldViewProjMatrix\tWORLDVIEWPROJECTION\r\n"
	"\tUNIFORM uConstantColour\t\t\tMATERIALCOLORAMBIENT\r\n"
	"\t\r\n"
	"\t// ATTRIBUTES\r\n"
	"\tATTRIBUTE\tinVertex\t\t\tPOSITION\r\n"
	"\tATTRIBUTE\tinTexCoord\t\t\tUV\r\n"
	"\r\n"
	"\t// SHADERS\t\r\n"
	"\tVERTEXSHADER   VertexShader\r\n"
	"\tFRAGMENTSHADER SolidColourFragmentShader\r\n"
	"[/EFFECT]\r\n"
	"\r\n"
	"[FRAGMENTSHADER] \r\n"
	"\tNAME \t\tSolidColourFragmentShader \r\n"
	"\r\n"
	"\t[GLSL_CODE]\r\n"
	"\t\t#version 300 es\r\n"
	"\r\n"
	"\t\tuniform lowp vec4 uConstantColour;\r\n"
	"\r\n"
	"\t\tlayout(location = 0) out lowp vec4 oColour;\r\n"
	"\r\n"
	"\t\tvoid main()\r\n"
	"\t\t{\r\n"
	"\t\t\toColour = uConstantColour;\r\n"
	"\t\t}\r\n"
	"\t[/GLSL_CODE]\r\n"
	"[/FRAGMENTSHADER]\r\n"
	"\r\n"
	"[VERTEXSHADER]\r\n"
	"\tNAME \t\tVertexShader\r\n"
	"\r\n"
	"\t[GLSL_CODE]\r\n"
	"\t\t#version 300 es\r\n"
	"\r\n"
	"\t\t#define VERTEX_ARRAY      0\r\n"
	"\t\t#define NORMAL_ARRAY      1\r\n"
	"\t\t#define TEXCOORD_ARRAY    2\r\n"
	"\r\n"
	"\t\tlayout(location = VERTEX_ARRAY)   in highp   vec3 inVertex;\r\n"
	"\t\tlayout(location = TEXCOORD_ARRAY) in mediump vec2 inTexCoord;\r\n"
	"\r\n"
	"\t\tuniform  mat4  uWorldViewProjMatrix; \r\n"
	"\r\n"
	"\t\tout mediump vec2 vTexCoord;\r\n"
	"\r\n"
	"\t\tvoid main() \r\n"
	"\t\t{ \r\n"
	"\t\t\t// pass-through position and texture coordinates\r\n"
	"\t\t\tgl_Position = uWorldViewProjMatrix * vec4(inVertex, 1.0);\r\n"
	"\t\t\tvTexCoord = inTexCoord;\r\n"
	"\t\t} \r\n"
	"\t[/GLSL_CODE]\r\n"
	"[/VERTEXSHADER]\r\n"
	"\r\n"
	"//\r\n"
	"// Renders the geometry using a texture\r\n"
	"//\r\n"
	"[EFFECT] \r\n"
	"\tNAME \tRenderCubeTexture\r\n"
	"\t\t\r\n"
	"\t// GLOBALS UNIFORMS\r\n"
	"\tUNIFORM uWorldViewProjMatrix\tWORLDVIEWPROJECTION\r\n"
	"\tUNIFORM uWorldIT\t\t\t\tWORLDIT\r\n"
	"\tUNIFORM uColour\t\t\t\t\tMATERIALCOLORAMBIENT\r\n"
	"\t\r\n"
	"\tUNIFORM sTexture\t\t\t\tTEXTURE0\r\n"
	"\t\r\n"
	"\t// ATTRIBUTES\r\n"
	"\tATTRIBUTE\tinVertex\t\t\tPOSITION\r\n"
	"\tATTRIBUTE\tinNormal\t\t\tNORMAL\r\n"
	"\tATTRIBUTE\tinTexCoord\t\t\tUV\r\n"
	"\r\n"
	"\t// SHADERS\t\r\n"
	"\tVERTEXSHADER   CubeTextureVertexShader\r\n"
	"\tFRAGMENTSHADER CubeTextureFragmentShader\r\n"
	"[/EFFECT]\r\n"
	"\r\n"
	"[FRAGMENTSHADER] \r\n"
	"\tNAME \t\tCubeTextureFragmentShader \r\n"
	"\r\n"
	"\t[GLSL_CODE]\r\n"
	"\t\t#version 300 es\r\n"
	"\r\n"
	"\t\tuniform samplerCube sTexture;\t\t\r\n"
	"\t\tuniform lowp vec4 uColour;\r\n"
	"\t\t\r\n"
	"\t\tin mediump vec3 vNormal;\r\n"
	"\t\t\r\n"
	"\t\tlayout(location = 0) out lowp vec4 oColour;\r\n"
	"\r\n"
	"\t\tvoid main()\r\n"
	"\t\t{\r\n"
	"\t\t\toColour = texture(sTexture, vNormal) * uColour;\r\n"
	"\t\t}\r\n"
	"\t[/GLSL_CODE]\r\n"
	"[/FRAGMENTSHADER]\r\n"
	"\r\n"
	"[VERTEXSHADER]\r\n"
	"\tNAME \t\tCubeTextureVertexShader\r\n"
	"\r\n"
	"\t[GLSL_CODE]\r\n"
	"\t\t#version 300 es\r\n"
	"\r\n"
	"\t\t#define VERTEX_ARRAY      0\r\n"
	"\t\t#define NORMAL_ARRAY      1\r\n"
	"\t\t#define TEXCOORD_ARRAY    2\r\n"
	"\r\n"
	"\t\tlayout(location = VERTEX_ARRAY)   in highp\tvec3 inVertex;\r\n"
	"\t\tlayout(location = NORMAL_ARRAY)   in highp\tvec3 inNormal;\r\n"
	"\r\n"
	"\t\tuniform  highp mat4  uWorldViewProjMatrix; \r\n"
	"\t\tuniform  highp mat3  uWorldIT;\r\n"
	"\r\n"
	"\t\tout mediump vec3 vNormal;\r\n"
	"\r\n"
	"\t\tvoid main() \r\n"
	"\t\t{ \r\n"
	"\t\t\t// pass-through position and texture coordinates\r\n"
	"\t\t\tgl_Position = uWorldViewProjMatrix * vec4(inVertex, 1.0);\r\n"
	"\t\t\tvNormal = uWorldIT * inNormal;\r\n"
	"\t\t} \r\n"
	"\t[/GLSL_CODE]\r\n"
	"[/VERTEXSHADER]";

// Register effect.pfx in memory file system at application startup time
static CPVRTMemoryFileSystem RegisterFile_effect_pfx("effect.pfx", _effect_pfx, 15323);

// ******** End: effect.pfx ********

