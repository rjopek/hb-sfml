/*
 * SFML library: Shader.c
 * version 2.5.1
 *
 * Copyright 2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbsfml.h"

/* Graphics/sfShader */
static HB_GARBAGE_FUNC( hb_sfShader_destructor )
{
   sfShader ** ppSfShader = ( sfShader ** ) Cargo;

   if( *ppSfShader )
   {
      sfShader_destroy( *ppSfShader );
      *ppSfShader = NULL;
   }
}

static const HB_GC_FUNCS s_gcSfShaderFuncs =
{
   hb_sfShader_destructor,
   hb_gcDummyMark
};

PHB_ITEM hb_sfShaderItemPut( PHB_ITEM pItem, sfShader * pSfShader )
{
   sfShader ** ppSfShader = ( sfShader ** ) hb_gcAllocate( sizeof( sfShader * ), &s_gcSfShaderFuncs );

   *ppSfShader = pSfShader;
   return hb_itemPutPtrGC( pItem, ppSfShader );
}

sfShader * hb_sfShader_param( int iParam )
{
   sfShader ** ppSfShader = ( sfShader ** ) hb_parptrGC( &s_gcSfShaderFuncs, iParam );

   if( ppSfShader && *ppSfShader )
   {
      return *ppSfShader;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
      return NULL;
   }
}

void hb_sfShader_ret( sfShader * pSfShader )
{
   hb_sfShaderItemPut( hb_stackReturnItem(), pSfShader );
}

// sfShader* sfShader_createFromFile(const char* vertexShaderFilename, const char* geometryShaderFilename, const char* fragmentShaderFilename);

// sfShader* sfShader_createFromMemory(const char* vertexShader, const char* geometryShader, const char* fragmentShader);

// sfShader* sfShader_createFromStream(sfInputStream* vertexShaderStream, sfInputStream* geometryShaderStream, sfInputStream* fragmentShaderStream);

// void sfShader_destroy(sfShader* shader);
HB_FUNC( SFSHADER_DESTROY )
{
   sfShader ** ppSfShader = ( sfShader ** ) hb_parptrGC( &s_gcSfShaderFuncs, 1 );

   if( ppSfShader && *ppSfShader )
   {
      sfShader_destroy( *ppSfShader );
      *ppSfShader = NULL;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void sfShader_setFloatUniform(sfShader* shader, const char* name, float x);

// void sfShader_setVec2Uniform(sfShader* shader, const char* name, sfGlslVec2 vector);

// void sfShader_setVec3Uniform(sfShader* shader, const char* name, sfGlslVec3 vector);

// void sfShader_setVec4Uniform(sfShader* shader, const char* name, sfGlslVec4 vector);

// void sfShader_setColorUniform(sfShader* shader, const char* name, sfColor color);

// void sfShader_setIntUniform(sfShader* shader, const char* name, int x);

// void sfShader_setIvec2Uniform(sfShader* shader, const char* name, sfGlslIvec2 vector);

// void sfShader_setIvec3Uniform(sfShader* shader, const char* name, sfGlslIvec3 vector);

// void sfShader_setIvec4Uniform(sfShader* shader, const char* name, sfGlslIvec4 vector);

// void sfShader_setIntColorUniform(sfShader* shader, const char* name, sfColor color);

// void sfShader_setBoolUniform(sfShader* shader, const char* name, sfBool x);

// void sfShader_setBvec2Uniform(sfShader* shader, const char* name, sfGlslBvec2 vector);

// void sfShader_setBvec3Uniform(sfShader* shader, const char* name, sfGlslBvec3 vector);

// void sfShader_setBvec4Uniform(sfShader* shader, const char* name, sfGlslBvec4 vector);

// void sfShader_setMat3Uniform(sfShader* shader, const char* name, const sfGlslMat3* matrix);

// void sfShader_setMat4Uniform(sfShader* shader, const char* name, const sfGlslMat4* matrix);

// void sfShader_setTextureUniform(sfShader* shader, const char* name, const sfTexture* texture);

// void sfShader_setCurrentTextureUniform(sfShader* shader, const char* name);

// void sfShader_setFloatUniformArray(sfShader* shader, const char* name, const float* scalarArray, size_t length);

// void sfShader_setVec2UniformArray(sfShader* shader, const char* name, const sfGlslVec2* vectorArray, size_t length);

// void sfShader_setVec3UniformArray(sfShader* shader, const char* name, const sfGlslVec3* vectorArray, size_t length);

// void sfShader_setVec4UniformArray(sfShader* shader, const char* name, const sfGlslVec4* vectorArray, size_t length);

// void sfShader_setMat3UniformArray(sfShader* shader, const char* name, const sfGlslMat3* matrixArray, size_t length);

// void sfShader_setMat4UniformArray(sfShader* shader, const char* name, const sfGlslMat4* matrixArray, size_t length);

// CSFML_DEPRECATED void sfShader_setFloatParameter(sfShader* shader, const char* name, float x);

// CSFML_DEPRECATED void sfShader_setFloat2Parameter(sfShader* shader, const char* name, float x, float y);

// CSFML_DEPRECATED void sfShader_setFloat3Parameter(sfShader* shader, const char* name, float x, float y, float z);

// CSFML_DEPRECATED void sfShader_setFloat4Parameter(sfShader* shader, const char* name, float x, float y, float z, float w);

// CSFML_DEPRECATED void sfShader_setVector2Parameter(sfShader* shader, const char* name, sfVector2f vector);

// CSFML_DEPRECATED void sfShader_setVector3Parameter(sfShader* shader, const char* name, sfVector3f vector);

// CSFML_DEPRECATED void sfShader_setColorParameter(sfShader* shader, const char* name, sfColor color);

// CSFML_DEPRECATED void sfShader_setTransformParameter(sfShader* shader, const char* name, sfTransform transform);

// CSFML_DEPRECATED void sfShader_setTextureParameter(sfShader* shader, const char* name, const sfTexture* texture);

// CSFML_DEPRECATED void sfShader_setCurrentTextureParameter(sfShader* shader, const char* name);

// unsigned int sfShader_getNativeHandle(const sfShader* shader);

// void sfShader_bind(const sfShader* shader);

// sfBool sfShader_isAvailable(void);

// sfBool sfShader_isGeometryAvailable(void);
