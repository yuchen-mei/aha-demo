#ifndef AMBERM3VX_ASSERT_H
#define AMBERM3VX_ASSERT_H

#ifdef __cplusplus
 extern "C" {
#endif

#if ! defined(assert_param)
#if defined(USE_FULL_ASSERT)
/**
  * @brief  The assert_param macro is used for function's parameters check.
  * @param  expr: If expr is false, it calls assert_failed function
  *         which reports the name of the source file and the source
  *         line number of the call that failed.
  *         If expr is true, it returns no value.
  * @retval None
  */
  #define assert_param(expr) ((expr) ? (void)0U : assert_failed((uint8_t *)__FILE__, __LINE__))
  void assert_failed(uint8_t* file, uint32_t line);
#else
  #define assert_param(expr) ((void)0U)
#endif // USE_FULL_ASSERT
#endif // assert_param

#ifdef __cplusplus
}
#endif

#endif // AMBERM3VX_ASSERT_H
