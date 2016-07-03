
#include <resourceTools.h>
#include <string>
#include <map>

static const unsigned char stopwords_en[]={
  0x61,0x0a,0x61,0x62,0x6c,0x65,0x0a,0x61,0x62,0x6f,0x75,0x74,0x0a,0x61,0x62,0x6f,
  0x76,0x65,0x0a,0x61,0x62,0x73,0x74,0x0a,0x61,0x63,0x63,0x6f,0x72,0x64,0x61,0x6e,
  0x63,0x65,0x0a,0x61,0x63,0x63,0x6f,0x72,0x64,0x69,0x6e,0x67,0x0a,0x61,0x63,0x63,
  0x6f,0x72,0x64,0x69,0x6e,0x67,0x6c,0x79,0x0a,0x61,0x63,0x72,0x6f,0x73,0x73,0x0a,
  0x61,0x63,0x74,0x0a,0x61,0x63,0x74,0x75,0x61,0x6c,0x6c,0x79,0x0a,0x61,0x64,0x64,
  0x65,0x64,0x0a,0x61,0x64,0x6a,0x0a,0x61,0x64,0x6f,0x70,0x74,0x65,0x64,0x0a,0x61,
  0x66,0x66,0x65,0x63,0x74,0x65,0x64,0x0a,0x61,0x66,0x66,0x65,0x63,0x74,0x69,0x6e,
  0x67,0x0a,0x61,0x66,0x66,0x65,0x63,0x74,0x73,0x0a,0x61,0x66,0x74,0x65,0x72,0x0a,
  0x61,0x66,0x74,0x65,0x72,0x77,0x61,0x72,0x64,0x73,0x0a,0x61,0x67,0x61,0x69,0x6e,
  0x0a,0x61,0x67,0x61,0x69,0x6e,0x73,0x74,0x0a,0x61,0x68,0x0a,0x61,0x6c,0x6c,0x0a,
  0x61,0x6c,0x6d,0x6f,0x73,0x74,0x0a,0x61,0x6c,0x6f,0x6e,0x65,0x0a,0x61,0x6c,0x6f,
  0x6e,0x67,0x0a,0x61,0x6c,0x72,0x65,0x61,0x64,0x79,0x0a,0x61,0x6c,0x73,0x6f,0x0a,
  0x61,0x6c,0x74,0x68,0x6f,0x75,0x67,0x68,0x0a,0x61,0x6c,0x77,0x61,0x79,0x73,0x0a,
  0x61,0x6d,0x0a,0x61,0x6d,0x6f,0x6e,0x67,0x0a,0x61,0x6d,0x6f,0x6e,0x67,0x73,0x74,
  0x0a,0x61,0x6e,0x0a,0x61,0x6e,0x64,0x0a,0x61,0x6e,0x6e,0x6f,0x75,0x6e,0x63,0x65,
  0x0a,0x61,0x6e,0x6f,0x74,0x68,0x65,0x72,0x0a,0x61,0x6e,0x79,0x0a,0x61,0x6e,0x79,
  0x62,0x6f,0x64,0x79,0x0a,0x61,0x6e,0x79,0x68,0x6f,0x77,0x0a,0x61,0x6e,0x79,0x6d,
  0x6f,0x72,0x65,0x0a,0x61,0x6e,0x79,0x6f,0x6e,0x65,0x0a,0x61,0x6e,0x79,0x74,0x68,
  0x69,0x6e,0x67,0x0a,0x61,0x6e,0x79,0x77,0x61,0x79,0x0a,0x61,0x6e,0x79,0x77,0x61,
  0x79,0x73,0x0a,0x61,0x6e,0x79,0x77,0x68,0x65,0x72,0x65,0x0a,0x61,0x70,0x70,0x61,
  0x72,0x65,0x6e,0x74,0x6c,0x79,0x0a,0x61,0x70,0x70,0x72,0x6f,0x78,0x69,0x6d,0x61,
  0x74,0x65,0x6c,0x79,0x0a,0x61,0x72,0x65,0x0a,0x61,0x72,0x65,0x6e,0x0a,0x61,0x72,
  0x65,0x6e,0x74,0x0a,0x61,0x72,0x69,0x73,0x65,0x0a,0x61,0x72,0x6f,0x75,0x6e,0x64,
  0x0a,0x61,0x73,0x0a,0x61,0x73,0x69,0x64,0x65,0x0a,0x61,0x73,0x6b,0x0a,0x61,0x73,
  0x6b,0x69,0x6e,0x67,0x0a,0x61,0x74,0x0a,0x61,0x75,0x74,0x68,0x0a,0x61,0x76,0x61,
  0x69,0x6c,0x61,0x62,0x6c,0x65,0x0a,0x61,0x77,0x61,0x79,0x0a,0x61,0x77,0x66,0x75,
  0x6c,0x6c,0x79,0x0a,0x62,0x0a,0x62,0x61,0x63,0x6b,0x0a,0x62,0x65,0x0a,0x62,0x65,
  0x63,0x61,0x6d,0x65,0x0a,0x62,0x65,0x63,0x61,0x75,0x73,0x65,0x0a,0x62,0x65,0x63,
  0x6f,0x6d,0x65,0x0a,0x62,0x65,0x63,0x6f,0x6d,0x65,0x73,0x0a,0x62,0x65,0x63,0x6f,
  0x6d,0x69,0x6e,0x67,0x0a,0x62,0x65,0x65,0x6e,0x0a,0x62,0x65,0x66,0x6f,0x72,0x65,
  0x0a,0x62,0x65,0x66,0x6f,0x72,0x65,0x68,0x61,0x6e,0x64,0x0a,0x62,0x65,0x67,0x69,
  0x6e,0x0a,0x62,0x65,0x67,0x69,0x6e,0x6e,0x69,0x6e,0x67,0x0a,0x62,0x65,0x67,0x69,
  0x6e,0x6e,0x69,0x6e,0x67,0x73,0x0a,0x62,0x65,0x67,0x69,0x6e,0x73,0x0a,0x62,0x65,
  0x68,0x69,0x6e,0x64,0x0a,0x62,0x65,0x69,0x6e,0x67,0x0a,0x62,0x65,0x6c,0x69,0x65,
  0x76,0x65,0x0a,0x62,0x65,0x6c,0x6f,0x77,0x0a,0x62,0x65,0x73,0x69,0x64,0x65,0x0a,
  0x62,0x65,0x73,0x69,0x64,0x65,0x73,0x0a,0x62,0x65,0x74,0x77,0x65,0x65,0x6e,0x0a,
  0x62,0x65,0x79,0x6f,0x6e,0x64,0x0a,0x62,0x69,0x6f,0x6c,0x0a,0x62,0x6f,0x74,0x68,
  0x0a,0x62,0x72,0x69,0x65,0x66,0x0a,0x62,0x72,0x69,0x65,0x66,0x6c,0x79,0x0a,0x62,
  0x75,0x74,0x0a,0x62,0x79,0x0a,0x63,0x0a,0x63,0x61,0x0a,0x63,0x61,0x6d,0x65,0x0a,
  0x63,0x61,0x6e,0x0a,0x63,0x61,0x6e,0x6e,0x6f,0x74,0x0a,0x63,0x61,0x6e,0x27,0x74,
  0x0a,0x63,0x61,0x75,0x73,0x65,0x0a,0x63,0x61,0x75,0x73,0x65,0x73,0x0a,0x63,0x65,
  0x72,0x74,0x61,0x69,0x6e,0x0a,0x63,0x65,0x72,0x74,0x61,0x69,0x6e,0x6c,0x79,0x0a,
  0x63,0x6f,0x0a,0x63,0x6f,0x6d,0x0a,0x63,0x6f,0x6d,0x65,0x0a,0x63,0x6f,0x6d,0x65,
  0x73,0x0a,0x63,0x6f,0x6e,0x74,0x61,0x69,0x6e,0x0a,0x63,0x6f,0x6e,0x74,0x61,0x69,
  0x6e,0x69,0x6e,0x67,0x0a,0x63,0x6f,0x6e,0x74,0x61,0x69,0x6e,0x73,0x0a,0x63,0x6f,
  0x75,0x6c,0x64,0x0a,0x63,0x6f,0x75,0x6c,0x64,0x6e,0x74,0x0a,0x64,0x0a,0x64,0x61,
  0x74,0x65,0x0a,0x64,0x69,0x64,0x0a,0x64,0x69,0x64,0x6e,0x27,0x74,0x0a,0x64,0x69,
  0x66,0x66,0x65,0x72,0x65,0x6e,0x74,0x0a,0x64,0x6f,0x0a,0x64,0x6f,0x65,0x73,0x0a,
  0x64,0x6f,0x65,0x73,0x6e,0x27,0x74,0x0a,0x64,0x6f,0x69,0x6e,0x67,0x0a,0x64,0x6f,
  0x6e,0x65,0x0a,0x64,0x6f,0x6e,0x27,0x74,0x0a,0x64,0x6f,0x77,0x6e,0x0a,0x64,0x6f,
  0x77,0x6e,0x77,0x61,0x72,0x64,0x73,0x0a,0x64,0x75,0x65,0x0a,0x64,0x75,0x72,0x69,
  0x6e,0x67,0x0a,0x65,0x0a,0x65,0x61,0x63,0x68,0x0a,0x65,0x64,0x0a,0x65,0x64,0x75,
  0x0a,0x65,0x66,0x66,0x65,0x63,0x74,0x0a,0x65,0x67,0x0a,0x65,0x69,0x67,0x68,0x74,
  0x0a,0x65,0x69,0x67,0x68,0x74,0x79,0x0a,0x65,0x69,0x74,0x68,0x65,0x72,0x0a,0x65,
  0x6c,0x73,0x65,0x0a,0x65,0x6c,0x73,0x65,0x77,0x68,0x65,0x72,0x65,0x0a,0x65,0x6e,
  0x64,0x0a,0x65,0x6e,0x64,0x69,0x6e,0x67,0x0a,0x65,0x6e,0x6f,0x75,0x67,0x68,0x0a,
  0x65,0x73,0x70,0x65,0x63,0x69,0x61,0x6c,0x6c,0x79,0x0a,0x65,0x74,0x0a,0x65,0x74,
  0x2d,0x61,0x6c,0x0a,0x65,0x74,0x63,0x0a,0x65,0x76,0x65,0x6e,0x0a,0x65,0x76,0x65,
  0x72,0x0a,0x65,0x76,0x65,0x72,0x79,0x0a,0x65,0x76,0x65,0x72,0x79,0x62,0x6f,0x64,
  0x79,0x0a,0x65,0x76,0x65,0x72,0x79,0x6f,0x6e,0x65,0x0a,0x65,0x76,0x65,0x72,0x79,
  0x74,0x68,0x69,0x6e,0x67,0x0a,0x65,0x76,0x65,0x72,0x79,0x77,0x68,0x65,0x72,0x65,
  0x0a,0x65,0x78,0x0a,0x65,0x78,0x63,0x65,0x70,0x74,0x0a,0x66,0x0a,0x66,0x61,0x72,
  0x0a,0x66,0x65,0x77,0x0a,0x66,0x66,0x0a,0x66,0x69,0x66,0x74,0x68,0x0a,0x66,0x69,
  0x72,0x73,0x74,0x0a,0x66,0x69,0x76,0x65,0x0a,0x66,0x69,0x78,0x0a,0x66,0x6f,0x6c,
  0x6c,0x6f,0x77,0x65,0x64,0x0a,0x66,0x6f,0x6c,0x6c,0x6f,0x77,0x69,0x6e,0x67,0x0a,
  0x66,0x6f,0x6c,0x6c,0x6f,0x77,0x73,0x0a,0x66,0x6f,0x72,0x0a,0x66,0x6f,0x72,0x6d,
  0x65,0x72,0x0a,0x66,0x6f,0x72,0x6d,0x65,0x72,0x6c,0x79,0x0a,0x66,0x6f,0x72,0x74,
  0x68,0x0a,0x66,0x6f,0x75,0x6e,0x64,0x0a,0x66,0x6f,0x75,0x72,0x0a,0x66,0x72,0x6f,
  0x6d,0x0a,0x66,0x75,0x72,0x74,0x68,0x65,0x72,0x0a,0x66,0x75,0x72,0x74,0x68,0x65,
  0x72,0x6d,0x6f,0x72,0x65,0x0a,0x67,0x0a,0x67,0x61,0x76,0x65,0x0a,0x67,0x65,0x74,
  0x0a,0x67,0x65,0x74,0x73,0x0a,0x67,0x65,0x74,0x74,0x69,0x6e,0x67,0x0a,0x67,0x69,
  0x76,0x65,0x0a,0x67,0x69,0x76,0x65,0x6e,0x0a,0x67,0x69,0x76,0x65,0x73,0x0a,0x67,
  0x69,0x76,0x69,0x6e,0x67,0x0a,0x67,0x6f,0x0a,0x67,0x6f,0x65,0x73,0x0a,0x67,0x6f,
  0x6e,0x65,0x0a,0x67,0x6f,0x74,0x0a,0x67,0x6f,0x74,0x74,0x65,0x6e,0x0a,0x68,0x0a,
  0x68,0x61,0x64,0x0a,0x68,0x61,0x70,0x70,0x65,0x6e,0x73,0x0a,0x68,0x61,0x72,0x64,
  0x6c,0x79,0x0a,0x68,0x61,0x73,0x0a,0x68,0x61,0x73,0x6e,0x27,0x74,0x0a,0x68,0x61,
  0x76,0x65,0x0a,0x68,0x61,0x76,0x65,0x6e,0x27,0x74,0x0a,0x68,0x61,0x76,0x69,0x6e,
  0x67,0x0a,0x68,0x65,0x0a,0x68,0x65,0x64,0x0a,0x68,0x65,0x6e,0x63,0x65,0x0a,0x68,
  0x65,0x72,0x0a,0x68,0x65,0x72,0x65,0x0a,0x68,0x65,0x72,0x65,0x61,0x66,0x74,0x65,
  0x72,0x0a,0x68,0x65,0x72,0x65,0x62,0x79,0x0a,0x68,0x65,0x72,0x65,0x69,0x6e,0x0a,
  0x68,0x65,0x72,0x65,0x73,0x0a,0x68,0x65,0x72,0x65,0x75,0x70,0x6f,0x6e,0x0a,0x68,
  0x65,0x72,0x73,0x0a,0x68,0x65,0x72,0x73,0x65,0x6c,0x66,0x0a,0x68,0x65,0x73,0x0a,
  0x68,0x69,0x0a,0x68,0x69,0x64,0x0a,0x68,0x69,0x6d,0x0a,0x68,0x69,0x6d,0x73,0x65,
  0x6c,0x66,0x0a,0x68,0x69,0x73,0x0a,0x68,0x69,0x74,0x68,0x65,0x72,0x0a,0x68,0x6f,
  0x6d,0x65,0x0a,0x68,0x6f,0x77,0x0a,0x68,0x6f,0x77,0x62,0x65,0x69,0x74,0x0a,0x68,
  0x6f,0x77,0x65,0x76,0x65,0x72,0x0a,0x68,0x75,0x6e,0x64,0x72,0x65,0x64,0x0a,0x69,
  0x0a,0x69,0x64,0x0a,0x69,0x65,0x0a,0x69,0x66,0x0a,0x69,0x27,0x6c,0x6c,0x0a,0x69,
  0x6d,0x0a,0x69,0x6d,0x6d,0x65,0x64,0x69,0x61,0x74,0x65,0x0a,0x69,0x6d,0x6d,0x65,
  0x64,0x69,0x61,0x74,0x65,0x6c,0x79,0x0a,0x69,0x6d,0x70,0x6f,0x72,0x74,0x61,0x6e,
  0x63,0x65,0x0a,0x69,0x6d,0x70,0x6f,0x72,0x74,0x61,0x6e,0x74,0x0a,0x69,0x6e,0x0a,
  0x69,0x6e,0x63,0x0a,0x69,0x6e,0x64,0x65,0x65,0x64,0x0a,0x69,0x6e,0x64,0x65,0x78,
  0x0a,0x69,0x6e,0x66,0x6f,0x72,0x6d,0x61,0x74,0x69,0x6f,0x6e,0x0a,0x69,0x6e,0x73,
  0x74,0x65,0x61,0x64,0x0a,0x69,0x6e,0x74,0x6f,0x0a,0x69,0x6e,0x76,0x65,0x6e,0x74,
  0x69,0x6f,0x6e,0x0a,0x69,0x6e,0x77,0x61,0x72,0x64,0x0a,0x69,0x73,0x0a,0x69,0x73,
  0x6e,0x27,0x74,0x0a,0x69,0x74,0x0a,0x69,0x74,0x64,0x0a,0x69,0x74,0x27,0x6c,0x6c,
  0x0a,0x69,0x74,0x73,0x0a,0x69,0x74,0x73,0x65,0x6c,0x66,0x0a,0x69,0x27,0x76,0x65,
  0x0a,0x6a,0x0a,0x6a,0x75,0x73,0x74,0x0a,0x6b,0x0a,0x6b,0x65,0x65,0x70,0x0a,0x6b,
  0x65,0x65,0x70,0x73,0x0a,0x6b,0x65,0x70,0x74,0x0a,0x6b,0x65,0x79,0x73,0x0a,0x6b,
  0x67,0x0a,0x6b,0x6d,0x0a,0x6b,0x6e,0x6f,0x77,0x0a,0x6b,0x6e,0x6f,0x77,0x6e,0x0a,
  0x6b,0x6e,0x6f,0x77,0x73,0x0a,0x6c,0x0a,0x6c,0x61,0x72,0x67,0x65,0x6c,0x79,0x0a,
  0x6c,0x61,0x73,0x74,0x0a,0x6c,0x61,0x74,0x65,0x6c,0x79,0x0a,0x6c,0x61,0x74,0x65,
  0x72,0x0a,0x6c,0x61,0x74,0x74,0x65,0x72,0x0a,0x6c,0x61,0x74,0x74,0x65,0x72,0x6c,
  0x79,0x0a,0x6c,0x65,0x61,0x73,0x74,0x0a,0x6c,0x65,0x73,0x73,0x0a,0x6c,0x65,0x73,
  0x74,0x0a,0x6c,0x65,0x74,0x0a,0x6c,0x65,0x74,0x73,0x0a,0x6c,0x69,0x6b,0x65,0x0a,
  0x6c,0x69,0x6b,0x65,0x64,0x0a,0x6c,0x69,0x6b,0x65,0x6c,0x79,0x0a,0x6c,0x69,0x6e,
  0x65,0x0a,0x6c,0x69,0x74,0x74,0x6c,0x65,0x0a,0x27,0x6c,0x6c,0x0a,0x6c,0x6f,0x6f,
  0x6b,0x0a,0x6c,0x6f,0x6f,0x6b,0x69,0x6e,0x67,0x0a,0x6c,0x6f,0x6f,0x6b,0x73,0x0a,
  0x6c,0x74,0x64,0x0a,0x6d,0x0a,0x6d,0x61,0x64,0x65,0x0a,0x6d,0x61,0x69,0x6e,0x6c,
  0x79,0x0a,0x6d,0x61,0x6b,0x65,0x0a,0x6d,0x61,0x6b,0x65,0x73,0x0a,0x6d,0x61,0x6e,
  0x79,0x0a,0x6d,0x61,0x79,0x0a,0x6d,0x61,0x79,0x62,0x65,0x0a,0x6d,0x65,0x0a,0x6d,
  0x65,0x61,0x6e,0x0a,0x6d,0x65,0x61,0x6e,0x73,0x0a,0x6d,0x65,0x61,0x6e,0x74,0x69,
  0x6d,0x65,0x0a,0x6d,0x65,0x61,0x6e,0x77,0x68,0x69,0x6c,0x65,0x0a,0x6d,0x65,0x72,
  0x65,0x6c,0x79,0x0a,0x6d,0x67,0x0a,0x6d,0x69,0x67,0x68,0x74,0x0a,0x6d,0x69,0x6c,
  0x6c,0x69,0x6f,0x6e,0x0a,0x6d,0x69,0x73,0x73,0x0a,0x6d,0x6c,0x0a,0x6d,0x6f,0x72,
  0x65,0x0a,0x6d,0x6f,0x72,0x65,0x6f,0x76,0x65,0x72,0x0a,0x6d,0x6f,0x73,0x74,0x0a,
  0x6d,0x6f,0x73,0x74,0x6c,0x79,0x0a,0x6d,0x72,0x0a,0x6d,0x72,0x73,0x0a,0x6d,0x75,
  0x63,0x68,0x0a,0x6d,0x75,0x67,0x0a,0x6d,0x75,0x73,0x74,0x0a,0x6d,0x79,0x0a,0x6d,
  0x79,0x73,0x65,0x6c,0x66,0x0a,0x6e,0x0a,0x6e,0x61,0x0a,0x6e,0x61,0x6d,0x65,0x0a,
  0x6e,0x61,0x6d,0x65,0x6c,0x79,0x0a,0x6e,0x61,0x79,0x0a,0x6e,0x64,0x0a,0x6e,0x65,
  0x61,0x72,0x0a,0x6e,0x65,0x61,0x72,0x6c,0x79,0x0a,0x6e,0x65,0x63,0x65,0x73,0x73,
  0x61,0x72,0x69,0x6c,0x79,0x0a,0x6e,0x65,0x63,0x65,0x73,0x73,0x61,0x72,0x79,0x0a,
  0x6e,0x65,0x65,0x64,0x0a,0x6e,0x65,0x65,0x64,0x73,0x0a,0x6e,0x65,0x69,0x74,0x68,
  0x65,0x72,0x0a,0x6e,0x65,0x76,0x65,0x72,0x0a,0x6e,0x65,0x76,0x65,0x72,0x74,0x68,
  0x65,0x6c,0x65,0x73,0x73,0x0a,0x6e,0x65,0x77,0x0a,0x6e,0x65,0x78,0x74,0x0a,0x6e,
  0x69,0x6e,0x65,0x0a,0x6e,0x69,0x6e,0x65,0x74,0x79,0x0a,0x6e,0x6f,0x0a,0x6e,0x6f,
  0x62,0x6f,0x64,0x79,0x0a,0x6e,0x6f,0x6e,0x0a,0x6e,0x6f,0x6e,0x65,0x0a,0x6e,0x6f,
  0x6e,0x65,0x74,0x68,0x65,0x6c,0x65,0x73,0x73,0x0a,0x6e,0x6f,0x6f,0x6e,0x65,0x0a,
  0x6e,0x6f,0x72,0x0a,0x6e,0x6f,0x72,0x6d,0x61,0x6c,0x6c,0x79,0x0a,0x6e,0x6f,0x73,
  0x0a,0x6e,0x6f,0x74,0x0a,0x6e,0x6f,0x74,0x65,0x64,0x0a,0x6e,0x6f,0x74,0x68,0x69,
  0x6e,0x67,0x0a,0x6e,0x6f,0x77,0x0a,0x6e,0x6f,0x77,0x68,0x65,0x72,0x65,0x0a,0x6f,
  0x0a,0x6f,0x62,0x74,0x61,0x69,0x6e,0x0a,0x6f,0x62,0x74,0x61,0x69,0x6e,0x65,0x64,
  0x0a,0x6f,0x62,0x76,0x69,0x6f,0x75,0x73,0x6c,0x79,0x0a,0x6f,0x66,0x0a,0x6f,0x66,
  0x66,0x0a,0x6f,0x66,0x74,0x65,0x6e,0x0a,0x6f,0x68,0x0a,0x6f,0x6b,0x0a,0x6f,0x6b,
  0x61,0x79,0x0a,0x6f,0x6c,0x64,0x0a,0x6f,0x6d,0x69,0x74,0x74,0x65,0x64,0x0a,0x6f,
  0x6e,0x0a,0x6f,0x6e,0x63,0x65,0x0a,0x6f,0x6e,0x65,0x0a,0x6f,0x6e,0x65,0x73,0x0a,
  0x6f,0x6e,0x6c,0x79,0x0a,0x6f,0x6e,0x74,0x6f,0x0a,0x6f,0x72,0x0a,0x6f,0x72,0x64,
  0x0a,0x6f,0x74,0x68,0x65,0x72,0x0a,0x6f,0x74,0x68,0x65,0x72,0x73,0x0a,0x6f,0x74,
  0x68,0x65,0x72,0x77,0x69,0x73,0x65,0x0a,0x6f,0x75,0x67,0x68,0x74,0x0a,0x6f,0x75,
  0x72,0x0a,0x6f,0x75,0x72,0x73,0x0a,0x6f,0x75,0x72,0x73,0x65,0x6c,0x76,0x65,0x73,
  0x0a,0x6f,0x75,0x74,0x0a,0x6f,0x75,0x74,0x73,0x69,0x64,0x65,0x0a,0x6f,0x76,0x65,
  0x72,0x0a,0x6f,0x76,0x65,0x72,0x61,0x6c,0x6c,0x0a,0x6f,0x77,0x69,0x6e,0x67,0x0a,
  0x6f,0x77,0x6e,0x0a,0x70,0x0a,0x70,0x61,0x67,0x65,0x0a,0x70,0x61,0x67,0x65,0x73,
  0x0a,0x70,0x61,0x72,0x74,0x0a,0x70,0x61,0x72,0x74,0x69,0x63,0x75,0x6c,0x61,0x72,
  0x0a,0x70,0x61,0x72,0x74,0x69,0x63,0x75,0x6c,0x61,0x72,0x6c,0x79,0x0a,0x70,0x61,
  0x73,0x74,0x0a,0x70,0x65,0x72,0x0a,0x70,0x65,0x72,0x68,0x61,0x70,0x73,0x0a,0x70,
  0x6c,0x61,0x63,0x65,0x64,0x0a,0x70,0x6c,0x65,0x61,0x73,0x65,0x0a,0x70,0x6c,0x75,
  0x73,0x0a,0x70,0x6f,0x6f,0x72,0x6c,0x79,0x0a,0x70,0x6f,0x73,0x73,0x69,0x62,0x6c,
  0x65,0x0a,0x70,0x6f,0x73,0x73,0x69,0x62,0x6c,0x79,0x0a,0x70,0x6f,0x74,0x65,0x6e,
  0x74,0x69,0x61,0x6c,0x6c,0x79,0x0a,0x70,0x70,0x0a,0x70,0x72,0x65,0x64,0x6f,0x6d,
  0x69,0x6e,0x61,0x6e,0x74,0x6c,0x79,0x0a,0x70,0x72,0x65,0x73,0x65,0x6e,0x74,0x0a,
  0x70,0x72,0x65,0x76,0x69,0x6f,0x75,0x73,0x6c,0x79,0x0a,0x70,0x72,0x69,0x6d,0x61,
  0x72,0x69,0x6c,0x79,0x0a,0x70,0x72,0x6f,0x62,0x61,0x62,0x6c,0x79,0x0a,0x70,0x72,
  0x6f,0x6d,0x70,0x74,0x6c,0x79,0x0a,0x70,0x72,0x6f,0x75,0x64,0x0a,0x70,0x72,0x6f,
  0x76,0x69,0x64,0x65,0x73,0x0a,0x70,0x75,0x74,0x0a,0x71,0x0a,0x71,0x75,0x65,0x0a,
  0x71,0x75,0x69,0x63,0x6b,0x6c,0x79,0x0a,0x71,0x75,0x69,0x74,0x65,0x0a,0x71,0x76,
  0x0a,0x72,0x0a,0x72,0x61,0x6e,0x0a,0x72,0x61,0x74,0x68,0x65,0x72,0x0a,0x72,0x64,
  0x0a,0x72,0x65,0x0a,0x72,0x65,0x61,0x64,0x69,0x6c,0x79,0x0a,0x72,0x65,0x61,0x6c,
  0x6c,0x79,0x0a,0x72,0x65,0x63,0x65,0x6e,0x74,0x0a,0x72,0x65,0x63,0x65,0x6e,0x74,
  0x6c,0x79,0x0a,0x72,0x65,0x66,0x0a,0x72,0x65,0x66,0x73,0x0a,0x72,0x65,0x67,0x61,
  0x72,0x64,0x69,0x6e,0x67,0x0a,0x72,0x65,0x67,0x61,0x72,0x64,0x6c,0x65,0x73,0x73,
  0x0a,0x72,0x65,0x67,0x61,0x72,0x64,0x73,0x0a,0x72,0x65,0x6c,0x61,0x74,0x65,0x64,
  0x0a,0x72,0x65,0x6c,0x61,0x74,0x69,0x76,0x65,0x6c,0x79,0x0a,0x72,0x65,0x73,0x65,
  0x61,0x72,0x63,0x68,0x0a,0x72,0x65,0x73,0x70,0x65,0x63,0x74,0x69,0x76,0x65,0x6c,
  0x79,0x0a,0x72,0x65,0x73,0x75,0x6c,0x74,0x65,0x64,0x0a,0x72,0x65,0x73,0x75,0x6c,
  0x74,0x69,0x6e,0x67,0x0a,0x72,0x65,0x73,0x75,0x6c,0x74,0x73,0x0a,0x72,0x69,0x67,
  0x68,0x74,0x0a,0x72,0x75,0x6e,0x0a,0x73,0x0a,0x73,0x61,0x69,0x64,0x0a,0x73,0x61,
  0x6d,0x65,0x0a,0x73,0x61,0x77,0x0a,0x73,0x61,0x79,0x0a,0x73,0x61,0x79,0x69,0x6e,
  0x67,0x0a,0x73,0x61,0x79,0x73,0x0a,0x73,0x65,0x63,0x0a,0x73,0x65,0x63,0x74,0x69,
  0x6f,0x6e,0x0a,0x73,0x65,0x65,0x0a,0x73,0x65,0x65,0x69,0x6e,0x67,0x0a,0x73,0x65,
  0x65,0x6d,0x0a,0x73,0x65,0x65,0x6d,0x65,0x64,0x0a,0x73,0x65,0x65,0x6d,0x69,0x6e,
  0x67,0x0a,0x73,0x65,0x65,0x6d,0x73,0x0a,0x73,0x65,0x65,0x6e,0x0a,0x73,0x65,0x6c,
  0x66,0x0a,0x73,0x65,0x6c,0x76,0x65,0x73,0x0a,0x73,0x65,0x6e,0x74,0x0a,0x73,0x65,
  0x76,0x65,0x6e,0x0a,0x73,0x65,0x76,0x65,0x72,0x61,0x6c,0x0a,0x73,0x68,0x61,0x6c,
  0x6c,0x0a,0x73,0x68,0x65,0x0a,0x73,0x68,0x65,0x64,0x0a,0x73,0x68,0x65,0x27,0x6c,
  0x6c,0x0a,0x73,0x68,0x65,0x73,0x0a,0x73,0x68,0x6f,0x75,0x6c,0x64,0x0a,0x73,0x68,
  0x6f,0x75,0x6c,0x64,0x6e,0x27,0x74,0x0a,0x73,0x68,0x6f,0x77,0x0a,0x73,0x68,0x6f,
  0x77,0x65,0x64,0x0a,0x73,0x68,0x6f,0x77,0x6e,0x0a,0x73,0x68,0x6f,0x77,0x6e,0x73,
  0x0a,0x73,0x68,0x6f,0x77,0x73,0x0a,0x73,0x69,0x67,0x6e,0x69,0x66,0x69,0x63,0x61,
  0x6e,0x74,0x0a,0x73,0x69,0x67,0x6e,0x69,0x66,0x69,0x63,0x61,0x6e,0x74,0x6c,0x79,
  0x0a,0x73,0x69,0x6d,0x69,0x6c,0x61,0x72,0x0a,0x73,0x69,0x6d,0x69,0x6c,0x61,0x72,
  0x6c,0x79,0x0a,0x73,0x69,0x6e,0x63,0x65,0x0a,0x73,0x69,0x78,0x0a,0x73,0x6c,0x69,
  0x67,0x68,0x74,0x6c,0x79,0x0a,0x73,0x6f,0x0a,0x73,0x6f,0x6d,0x65,0x0a,0x73,0x6f,
  0x6d,0x65,0x62,0x6f,0x64,0x79,0x0a,0x73,0x6f,0x6d,0x65,0x68,0x6f,0x77,0x0a,0x73,
  0x6f,0x6d,0x65,0x6f,0x6e,0x65,0x0a,0x73,0x6f,0x6d,0x65,0x74,0x68,0x61,0x6e,0x0a,
  0x73,0x6f,0x6d,0x65,0x74,0x68,0x69,0x6e,0x67,0x0a,0x73,0x6f,0x6d,0x65,0x74,0x69,
  0x6d,0x65,0x0a,0x73,0x6f,0x6d,0x65,0x74,0x69,0x6d,0x65,0x73,0x0a,0x73,0x6f,0x6d,
  0x65,0x77,0x68,0x61,0x74,0x0a,0x73,0x6f,0x6d,0x65,0x77,0x68,0x65,0x72,0x65,0x0a,
  0x73,0x6f,0x6f,0x6e,0x0a,0x73,0x6f,0x72,0x72,0x79,0x0a,0x73,0x70,0x65,0x63,0x69,
  0x66,0x69,0x63,0x61,0x6c,0x6c,0x79,0x0a,0x73,0x70,0x65,0x63,0x69,0x66,0x69,0x65,
  0x64,0x0a,0x73,0x70,0x65,0x63,0x69,0x66,0x79,0x0a,0x73,0x70,0x65,0x63,0x69,0x66,
  0x79,0x69,0x6e,0x67,0x0a,0x73,0x74,0x61,0x74,0x65,0x0a,0x73,0x74,0x61,0x74,0x65,
  0x73,0x0a,0x73,0x74,0x69,0x6c,0x6c,0x0a,0x73,0x74,0x6f,0x70,0x0a,0x73,0x74,0x72,
  0x6f,0x6e,0x67,0x6c,0x79,0x0a,0x73,0x75,0x62,0x0a,0x73,0x75,0x62,0x73,0x74,0x61,
  0x6e,0x74,0x69,0x61,0x6c,0x6c,0x79,0x0a,0x73,0x75,0x63,0x63,0x65,0x73,0x73,0x66,
  0x75,0x6c,0x6c,0x79,0x0a,0x73,0x75,0x63,0x68,0x0a,0x73,0x75,0x66,0x66,0x69,0x63,
  0x69,0x65,0x6e,0x74,0x6c,0x79,0x0a,0x73,0x75,0x67,0x67,0x65,0x73,0x74,0x0a,0x73,
  0x75,0x70,0x0a,0x73,0x75,0x72,0x65,0x0a,0x09,0x74,0x0a,0x74,0x61,0x6b,0x65,0x0a,
  0x74,0x61,0x6b,0x65,0x6e,0x0a,0x74,0x61,0x6b,0x69,0x6e,0x67,0x0a,0x74,0x65,0x6c,
  0x6c,0x0a,0x74,0x65,0x6e,0x64,0x73,0x0a,0x74,0x68,0x0a,0x74,0x68,0x61,0x6e,0x0a,
  0x74,0x68,0x61,0x6e,0x6b,0x0a,0x74,0x68,0x61,0x6e,0x6b,0x73,0x0a,0x74,0x68,0x61,
  0x6e,0x78,0x0a,0x74,0x68,0x61,0x74,0x0a,0x74,0x68,0x61,0x74,0x27,0x6c,0x6c,0x0a,
  0x74,0x68,0x61,0x74,0x73,0x0a,0x74,0x68,0x61,0x74,0x27,0x76,0x65,0x0a,0x74,0x68,
  0x65,0x0a,0x74,0x68,0x65,0x69,0x72,0x0a,0x74,0x68,0x65,0x69,0x72,0x73,0x0a,0x74,
  0x68,0x65,0x6d,0x0a,0x74,0x68,0x65,0x6d,0x73,0x65,0x6c,0x76,0x65,0x73,0x0a,0x74,
  0x68,0x65,0x6e,0x0a,0x74,0x68,0x65,0x6e,0x63,0x65,0x0a,0x74,0x68,0x65,0x72,0x65,
  0x0a,0x74,0x68,0x65,0x72,0x65,0x61,0x66,0x74,0x65,0x72,0x0a,0x74,0x68,0x65,0x72,
  0x65,0x62,0x79,0x0a,0x74,0x68,0x65,0x72,0x65,0x64,0x0a,0x74,0x68,0x65,0x72,0x65,
  0x66,0x6f,0x72,0x65,0x0a,0x74,0x68,0x65,0x72,0x65,0x69,0x6e,0x0a,0x74,0x68,0x65,
  0x72,0x65,0x27,0x6c,0x6c,0x0a,0x74,0x68,0x65,0x72,0x65,0x6f,0x66,0x0a,0x74,0x68,
  0x65,0x72,0x65,0x72,0x65,0x0a,0x74,0x68,0x65,0x72,0x65,0x73,0x0a,0x74,0x68,0x65,
  0x72,0x65,0x74,0x6f,0x0a,0x74,0x68,0x65,0x72,0x65,0x75,0x70,0x6f,0x6e,0x0a,0x74,
  0x68,0x65,0x72,0x65,0x27,0x76,0x65,0x0a,0x74,0x68,0x65,0x73,0x65,0x0a,0x74,0x68,
  0x65,0x79,0x0a,0x74,0x68,0x65,0x79,0x64,0x0a,0x74,0x68,0x65,0x79,0x27,0x6c,0x6c,
  0x0a,0x74,0x68,0x65,0x79,0x72,0x65,0x0a,0x74,0x68,0x65,0x79,0x27,0x76,0x65,0x0a,
  0x74,0x68,0x69,0x6e,0x6b,0x0a,0x74,0x68,0x69,0x73,0x0a,0x74,0x68,0x6f,0x73,0x65,
  0x0a,0x74,0x68,0x6f,0x75,0x0a,0x74,0x68,0x6f,0x75,0x67,0x68,0x0a,0x74,0x68,0x6f,
  0x75,0x67,0x68,0x68,0x0a,0x74,0x68,0x6f,0x75,0x73,0x61,0x6e,0x64,0x0a,0x74,0x68,
  0x72,0x6f,0x75,0x67,0x0a,0x74,0x68,0x72,0x6f,0x75,0x67,0x68,0x0a,0x74,0x68,0x72,
  0x6f,0x75,0x67,0x68,0x6f,0x75,0x74,0x0a,0x74,0x68,0x72,0x75,0x0a,0x74,0x68,0x75,
  0x73,0x0a,0x74,0x69,0x6c,0x0a,0x74,0x69,0x70,0x0a,0x74,0x6f,0x0a,0x74,0x6f,0x67,
  0x65,0x74,0x68,0x65,0x72,0x0a,0x74,0x6f,0x6f,0x0a,0x74,0x6f,0x6f,0x6b,0x0a,0x74,
  0x6f,0x77,0x61,0x72,0x64,0x0a,0x74,0x6f,0x77,0x61,0x72,0x64,0x73,0x0a,0x74,0x72,
  0x69,0x65,0x64,0x0a,0x74,0x72,0x69,0x65,0x73,0x0a,0x74,0x72,0x75,0x6c,0x79,0x0a,
  0x74,0x72,0x79,0x0a,0x74,0x72,0x79,0x69,0x6e,0x67,0x0a,0x74,0x73,0x0a,0x74,0x77,
  0x69,0x63,0x65,0x0a,0x74,0x77,0x6f,0x0a,0x75,0x0a,0x75,0x6e,0x0a,0x75,0x6e,0x64,
  0x65,0x72,0x0a,0x75,0x6e,0x66,0x6f,0x72,0x74,0x75,0x6e,0x61,0x74,0x65,0x6c,0x79,
  0x0a,0x75,0x6e,0x6c,0x65,0x73,0x73,0x0a,0x75,0x6e,0x6c,0x69,0x6b,0x65,0x0a,0x75,
  0x6e,0x6c,0x69,0x6b,0x65,0x6c,0x79,0x0a,0x75,0x6e,0x74,0x69,0x6c,0x0a,0x75,0x6e,
  0x74,0x6f,0x0a,0x75,0x70,0x0a,0x75,0x70,0x6f,0x6e,0x0a,0x75,0x70,0x73,0x0a,0x75,
  0x73,0x0a,0x75,0x73,0x65,0x0a,0x75,0x73,0x65,0x64,0x0a,0x75,0x73,0x65,0x66,0x75,
  0x6c,0x0a,0x75,0x73,0x65,0x66,0x75,0x6c,0x6c,0x79,0x0a,0x75,0x73,0x65,0x66,0x75,
  0x6c,0x6e,0x65,0x73,0x73,0x0a,0x75,0x73,0x65,0x73,0x0a,0x75,0x73,0x69,0x6e,0x67,
  0x0a,0x75,0x73,0x75,0x61,0x6c,0x6c,0x79,0x0a,0x76,0x0a,0x76,0x61,0x6c,0x75,0x65,
  0x0a,0x76,0x61,0x72,0x69,0x6f,0x75,0x73,0x0a,0x27,0x76,0x65,0x0a,0x76,0x65,0x72,
  0x79,0x0a,0x76,0x69,0x61,0x0a,0x76,0x69,0x7a,0x0a,0x76,0x6f,0x6c,0x0a,0x76,0x6f,
  0x6c,0x73,0x0a,0x76,0x73,0x0a,0x77,0x0a,0x77,0x61,0x6e,0x74,0x0a,0x77,0x61,0x6e,
  0x74,0x73,0x0a,0x77,0x61,0x73,0x0a,0x77,0x61,0x73,0x6e,0x27,0x74,0x0a,0x77,0x61,
  0x79,0x0a,0x77,0x65,0x0a,0x77,0x65,0x64,0x0a,0x77,0x65,0x6c,0x63,0x6f,0x6d,0x65,
  0x0a,0x77,0x65,0x27,0x6c,0x6c,0x0a,0x77,0x65,0x6e,0x74,0x0a,0x77,0x65,0x72,0x65,
  0x0a,0x77,0x65,0x72,0x65,0x6e,0x27,0x74,0x0a,0x77,0x65,0x27,0x76,0x65,0x0a,0x77,
  0x68,0x61,0x74,0x0a,0x77,0x68,0x61,0x74,0x65,0x76,0x65,0x72,0x0a,0x77,0x68,0x61,
  0x74,0x27,0x6c,0x6c,0x0a,0x77,0x68,0x61,0x74,0x73,0x0a,0x77,0x68,0x65,0x6e,0x0a,
  0x77,0x68,0x65,0x6e,0x63,0x65,0x0a,0x77,0x68,0x65,0x6e,0x65,0x76,0x65,0x72,0x0a,
  0x77,0x68,0x65,0x72,0x65,0x0a,0x77,0x68,0x65,0x72,0x65,0x61,0x66,0x74,0x65,0x72,
  0x0a,0x77,0x68,0x65,0x72,0x65,0x61,0x73,0x0a,0x77,0x68,0x65,0x72,0x65,0x62,0x79,
  0x0a,0x77,0x68,0x65,0x72,0x65,0x69,0x6e,0x0a,0x77,0x68,0x65,0x72,0x65,0x73,0x0a,
  0x77,0x68,0x65,0x72,0x65,0x75,0x70,0x6f,0x6e,0x0a,0x77,0x68,0x65,0x72,0x65,0x76,
  0x65,0x72,0x0a,0x77,0x68,0x65,0x74,0x68,0x65,0x72,0x0a,0x77,0x68,0x69,0x63,0x68,
  0x0a,0x77,0x68,0x69,0x6c,0x65,0x0a,0x77,0x68,0x69,0x6d,0x0a,0x77,0x68,0x69,0x74,
  0x68,0x65,0x72,0x0a,0x77,0x68,0x6f,0x0a,0x77,0x68,0x6f,0x64,0x0a,0x77,0x68,0x6f,
  0x65,0x76,0x65,0x72,0x0a,0x77,0x68,0x6f,0x6c,0x65,0x0a,0x77,0x68,0x6f,0x27,0x6c,
  0x6c,0x0a,0x77,0x68,0x6f,0x6d,0x0a,0x77,0x68,0x6f,0x6d,0x65,0x76,0x65,0x72,0x0a,
  0x77,0x68,0x6f,0x73,0x0a,0x77,0x68,0x6f,0x73,0x65,0x0a,0x77,0x68,0x79,0x0a,0x77,
  0x69,0x64,0x65,0x6c,0x79,0x0a,0x77,0x69,0x6c,0x6c,0x69,0x6e,0x67,0x0a,0x77,0x69,
  0x73,0x68,0x0a,0x77,0x69,0x74,0x68,0x0a,0x77,0x69,0x74,0x68,0x69,0x6e,0x0a,0x77,
  0x69,0x74,0x68,0x6f,0x75,0x74,0x0a,0x77,0x6f,0x6e,0x27,0x74,0x0a,0x77,0x6f,0x72,
  0x64,0x73,0x0a,0x77,0x6f,0x72,0x6c,0x64,0x0a,0x77,0x6f,0x75,0x6c,0x64,0x0a,0x77,
  0x6f,0x75,0x6c,0x64,0x6e,0x27,0x74,0x0a,0x77,0x77,0x77,0x0a,0x78,0x0a,0x79,0x0a,
  0x79,0x65,0x73,0x0a,0x79,0x65,0x74,0x0a,0x79,0x6f,0x75,0x0a,0x79,0x6f,0x75,0x64,
  0x0a,0x79,0x6f,0x75,0x27,0x6c,0x6c,0x0a,0x79,0x6f,0x75,0x72,0x0a,0x79,0x6f,0x75,
  0x72,0x65,0x0a,0x79,0x6f,0x75,0x72,0x73,0x0a,0x79,0x6f,0x75,0x72,0x73,0x65,0x6c,
  0x66,0x0a,0x79,0x6f,0x75,0x72,0x73,0x65,0x6c,0x76,0x65,0x73,0x0a,0x79,0x6f,0x75,
  0x27,0x76,0x65,0x0a,0x7a,0x0a,0x7a,0x65,0x72,0x6f,0x0a
  };

static const unsigned char stopwords_fra[]={
  0x61,0x6c,0x6f,0x72,0x73,0x0a,0x61,0x75,0x0a,0x61,0x75,0x63,0x75,0x6e,0x73,0x0a,
  0x61,0x75,0x73,0x73,0x69,0x0a,0x61,0x75,0x74,0x72,0x65,0x0a,0x61,0x76,0x61,0x6e,
  0x74,0x0a,0x61,0x76,0x65,0x63,0x0a,0x61,0x76,0x6f,0x69,0x72,0x0a,0x62,0x6f,0x6e,
  0x0a,0x63,0x61,0x72,0x0a,0x63,0x65,0x0a,0x63,0x65,0x6c,0x61,0x0a,0x63,0x65,0x73,
  0x0a,0x63,0x65,0x75,0x78,0x0a,0x63,0x68,0x61,0x71,0x75,0x65,0x0a,0x63,0x69,0x0a,
  0x63,0x6f,0x6d,0x6d,0x65,0x0a,0x63,0x6f,0x6d,0x6d,0x65,0x6e,0x74,0x0a,0x64,0x61,
  0x6e,0x73,0x0a,0x64,0x65,0x73,0x0a,0x64,0x75,0x0a,0x64,0x65,0x64,0x61,0x6e,0x73,
  0x0a,0x64,0x65,0x68,0x6f,0x72,0x73,0x0a,0x64,0x65,0x70,0x75,0x69,0x73,0x0a,0x64,
  0x65,0x75,0x78,0x0a,0x64,0x65,0x76,0x72,0x61,0x69,0x74,0x0a,0x64,0x6f,0x69,0x74,
  0x0a,0x64,0x6f,0x6e,0x63,0x0a,0x64,0x6f,0x73,0x0a,0x64,0x72,0x6f,0x69,0x74,0x65,
  0x0a,0x64,0xc3,0xa9,0x62,0x75,0x74,0x0a,0x65,0x6c,0x6c,0x65,0x0a,0x65,0x6c,0x6c,
  0x65,0x73,0x0a,0x65,0x6e,0x0a,0x65,0x6e,0x63,0x6f,0x72,0x65,0x0a,0x65,0x73,0x73,
  0x61,0x69,0x0a,0x65,0x73,0x74,0x0a,0x65,0x74,0x0a,0x65,0x75,0x0a,0x66,0x61,0x69,
  0x74,0x0a,0x66,0x61,0x69,0x74,0x65,0x73,0x0a,0x66,0x6f,0x69,0x73,0x0a,0x66,0x6f,
  0x6e,0x74,0x0a,0x66,0x6f,0x72,0x63,0x65,0x0a,0x68,0x61,0x75,0x74,0x0a,0x68,0x6f,
  0x72,0x73,0x0a,0x69,0x63,0x69,0x0a,0x69,0x6c,0x0a,0x69,0x6c,0x73,0x0a,0x6a,0x65,
  0x0a,0x6c,0x61,0x0a,0x6c,0x65,0x0a,0x6c,0x65,0x73,0x0a,0x6c,0x65,0x75,0x72,0x0a,
  0x6c,0xc3,0xa0,0x0a,0x6d,0x61,0x0a,0x6d,0x61,0x69,0x6e,0x74,0x65,0x6e,0x61,0x6e,
  0x74,0x0a,0x6d,0x61,0x69,0x73,0x0a,0x6d,0x65,0x73,0x0a,0x6d,0x69,0x6e,0x65,0x0a,
  0x6d,0x6f,0x69,0x6e,0x73,0x0a,0x6d,0x6f,0x6e,0x0a,0x6d,0x6f,0x74,0x0a,0x6d,0xc3,
  0xaa,0x6d,0x65,0x0a,0x6e,0x69,0x0a,0x6e,0x6f,0x6d,0x6d,0xc3,0xa9,0x73,0x0a,0x6e,
  0x6f,0x74,0x72,0x65,0x0a,0x6e,0x6f,0x75,0x73,0x0a,0x6e,0x6f,0x75,0x76,0x65,0x61,
  0x75,0x78,0x0a,0x6f,0x75,0x0a,0x6f,0xc3,0xb9,0x0a,0x70,0x61,0x72,0x0a,0x70,0x61,
  0x72,0x63,0x65,0x0a,0x70,0x61,0x72,0x6f,0x6c,0x65,0x0a,0x70,0x61,0x73,0x0a,0x70,
  0x65,0x72,0x73,0x6f,0x6e,0x6e,0x65,0x73,0x0a,0x70,0x65,0x75,0x74,0x0a,0x70,0x65,
  0x75,0x0a,0x70,0x69,0xc3,0xa8,0x63,0x65,0x0a,0x70,0x6c,0x75,0x70,0x61,0x72,0x74,
  0x0a,0x70,0x6f,0x75,0x72,0x0a,0x70,0x6f,0x75,0x72,0x71,0x75,0x6f,0x69,0x0a,0x71,
  0x75,0x61,0x6e,0x64,0x0a,0x71,0x75,0x65,0x0a,0x71,0x75,0x65,0x6c,0x0a,0x71,0x75,
  0x65,0x6c,0x6c,0x65,0x0a,0x71,0x75,0x65,0x6c,0x6c,0x65,0x73,0x0a,0x71,0x75,0x65,
  0x6c,0x73,0x0a,0x71,0x75,0x69,0x0a,0x73,0x61,0x0a,0x73,0x61,0x6e,0x73,0x0a,0x73,
  0x65,0x73,0x0a,0x73,0x65,0x75,0x6c,0x65,0x6d,0x65,0x6e,0x74,0x0a,0x73,0x69,0x0a,
  0x73,0x69,0x65,0x6e,0x0a,0x73,0x6f,0x6e,0x0a,0x73,0x6f,0x6e,0x74,0x0a,0x73,0x6f,
  0x75,0x73,0x0a,0x73,0x6f,0x79,0x65,0x7a,0x0a,0x73,0x75,0x72,0x0a,0x74,0x61,0x0a,
  0x74,0x61,0x6e,0x64,0x69,0x73,0x0a,0x74,0x65,0x6c,0x6c,0x65,0x6d,0x65,0x6e,0x74,
  0x0a,0x74,0x65,0x6c,0x73,0x0a,0x74,0x65,0x73,0x0a,0x74,0x6f,0x6e,0x0a,0x74,0x6f,
  0x75,0x73,0x0a,0x74,0x6f,0x75,0x74,0x0a,0x74,0x72,0x6f,0x70,0x0a,0x74,0x72,0xc3,
  0xa8,0x73,0x0a,0x74,0x75,0x0a,0x76,0x61,0x6c,0x65,0x75,0x72,0x0a,0x76,0x6f,0x69,
  0x65,0x0a,0x76,0x6f,0x69,0x65,0x6e,0x74,0x0a,0x76,0x6f,0x6e,0x74,0x0a,0x76,0x6f,
  0x74,0x72,0x65,0x0a,0x76,0x6f,0x75,0x73,0x0a,0x76,0x75,0x0a,0xc3,0xa7,0x61,0x0a,
  0xc3,0xa9,0x74,0x61,0x69,0x65,0x6e,0x74,0x0a,0xc3,0xa9,0x74,0x61,0x74,0x0a,0xc3,
  0xa9,0x74,0x69,0x6f,0x6e,0x73,0x0a,0xc3,0xa9,0x74,0xc3,0xa9,0x0a,0xc3,0xaa,0x74,
  0x72,0x65,0x0a
  };

static const unsigned char stopwords_he[]={
  0xd7,0xa9,0xd7,0x9c,0x0d,0x0a,0xd7,0x90,0xd7,0xaa,0x0d,0x0a,0xd7,0xa2,0xd7,0x9c,
  0x0d,0x0a,0xd7,0x9c,0xd7,0x90,0x0d,0x0a,0xd7,0x9b,0xd7,0x99,0x0d,0x0a,0xd7,0xa2,
  0xd7,0x9d,0x0d,0x0a,0xd7,0x94,0xd7,0x95,0xd7,0x90,0x0d,0x0a,0xd7,0x92,0xd7,0x9d,
  0x0d,0x0a,0xd7,0x91,0x0d,0x0a,0xd7,0x96,0xd7,0x94,0x0d,0x0a,0xd7,0x94,0xd7,0x99,
  0xd7,0x90,0x0d,0x0a,0xd7,0x9b,0xd7,0x9c,0x0d,0x0a,0xd7,0x99,0xd7,0x95,0xd7,0xaa,
  0xd7,0xa8,0x0d,0x0a,0xd7,0x90,0xd7,0x95,0x0d,0x0a,0xd7,0x90,0xd7,0x91,0xd7,0x9c,
  0x0d,0x0a,0xd7,0x91,0xd7,0x99,0xd7,0x9f,0x0d,0x0a,0xd7,0x94,0xd7,0x99,0xd7,0x94,
  0x0d,0x0a,0xd7,0x90,0xd7,0x9d,0x0d,0x0a,0xd7,0x9e,0xd7,0x99,0xd7,0x9c,0xd7,0x99,
  0xd7,0x95,0xd7,0x9f,0x0d,0x0a,0xd7,0x99,0xd7,0xa9,0x0d,0x0a,0xd7,0x9b,0xd7,0x9a,
  0x0d,0x0a,0xd7,0x90,0xd7,0xa0,0xd7,0x99,0x0d,0x0a,0xd7,0x94,0xd7,0x9d,0x0d,0x0a,
  0xd7,0x93,0xd7,0x95,0xd7,0x9c,0xd7,0xa8,0x0d,0x0a,0xd7,0x90,0xd7,0x9e,0xd7,0xa8,
  0x0d,0x0a,0xd7,0xa2,0xd7,0x93,0x0d,0x0a,0xd7,0x9c,0xd7,0x90,0xd7,0x97,0xd7,0xa8,
  0x0d,0x0a,0xd7,0x99,0xd7,0xa9,0xd7,0xa8,0xd7,0x90,0xd7,0x9c,0x0d,0x0a,0xd7,0xa8,
  0xd7,0xa7,0x0d,0x0a,0xd7,0xa9,0xd7,0xa7,0xd7,0x9c,0x0d,0x0a,0xd7,0x9b,0xd7,0x93,
  0xd7,0x99,0x0d,0x0a,0xd7,0x9e,0xd7,0x94,0x0d,0x0a,0xd7,0x9c,0xd7,0xa4,0xd7,0xa0,
  0xd7,0x99,0x0d,0x0a,0xd7,0x90,0xd7,0x97,0xd7,0x93,0x0d,0x0a,0xd7,0x94,0xd7,0x97,
  0xd7,0x91,0xd7,0xa8,0xd7,0x94,0x0d,0x0a,0xd7,0x9b,0xd7,0x9e,0xd7,0x95,0x0d,0x0a,
  0xd7,0x96,0xd7,0x90,0xd7,0xaa,0x0d,0x0a,0xd7,0x94,0xd7,0x99,0xd7,0x95,0xd7,0x9d,
  0x0d,0x0a,0xd7,0x90,0xd7,0x9a,0x0d,0x0a,0xd7,0x9c,0x0d,0x0a,0xd7,0x94,0x0d,0x0a,
  0xd7,0x9b,0x0d,0x0a,0xd7,0x90,0xd7,0x99,0xd7,0x9f,0x0d,0x0a,0xd7,0x90,0xd7,0xaa,
  0xd7,0x9e,0xd7,0x95,0xd7,0x9c,0x0d,0x0a,0xd7,0xa9,0xd7,0x9c,0xd7,0x90,0x0d,0x0a,
  0xd7,0x9b,0xd7,0x91,0xd7,0xa8,0x0d,0x0a,0xd7,0xa2,0xd7,0x95,0xd7,0x93,0x0d,0x0a,
  0xd7,0x9c,0xd7,0x95,0x0d,0x0a,0xd7,0x96,0xd7,0x95,0x0d,0x0a,0xd7,0x90,0xd7,0x9c,
  0x0d,0x0a,0xd7,0x91,0xd7,0x9f,0x0d,0x0a,0xd7,0x90,0xd7,0x95,0xd7,0xaa,0xd7,0x95,
  0x0d,0x0a,0xd7,0xa9,0xd7,0xa0,0xd7,0x99,0x0d,0x0a,0xd7,0x91,0xd7,0x99,0xd7,0xaa,
  0x0d,0x0a,0xd7,0x99,0xd7,0x93,0xd7,0x99,0x0d,0x0a,0xd7,0x9b,0xd7,0x9e,0xd7,0x94,
  0x0d,0x0a,0xd7,0x91,0xd7,0x99,0xd7,0x95,0xd7,0xaa,0xd7,0xa8,0x0d,0x0a,0xd7,0x95,
  0xd7,0x9c,0xd7,0x90,0x0d,0x0a,0xd7,0x94,0xd7,0x9e,0xd7,0x9e,0xd7,0xa9,0xd7,0x9c,
  0xd7,0x94,0x0d,0x0a,0xd7,0x90,0xd7,0x97,0xd7,0xa8,0xd7,0x99,0x0d,0x0a,0xd7,0x97,
  0xd7,0x91,0xd7,0xa8,0xd7,0xaa,0x0d,0x0a,0xd7,0x94,0xd7,0x99,0xd7,0xaa,0xd7,0x94,
  0x0d,0x0a,0xd7,0xa9,0xd7,0x9c,0xd7,0x95,0x0d,0x0a,0xd7,0x94,0xd7,0x99,0xd7,0x95,
  0x0d,0x0a,0xd7,0xa0,0xd7,0x92,0xd7,0x93,0x0d,0x0a,0xd7,0x91,0xd7,0x9b,0xd7,0x9c,
  0x0d,0x0a,0xd7,0x90,0xd7,0x91,0xd7,0x99,0xd7,0x91,0x0d,0x0a,0xd7,0xa8,0xd7,0x90,
  0xd7,0xa9,0x0d,0x0a,0xd7,0x91,0xd7,0x99,0xd7,0xa9,0xd7,0xa8,0xd7,0x90,0xd7,0x9c,
  0x0d,0x0a,0xd7,0x9c,0xd7,0x99,0x0d,0x0a,0xd7,0xa9,0xd7,0xa0,0xd7,0x99,0xd7,0x9d,
  0x0d,0x0a,0xd7,0xa4,0xd7,0x99,0x0d,0x0a,0xd7,0x91,0xd7,0x95,0x0d,0x0a,0xd7,0x9e,
  0x0d,0x0a,0xd7,0x9e,0xd7,0x90,0xd7,0x95,0xd7,0x93,0x0d,0x0a,0xd7,0x9c,0xd7,0x94,
  0xd7,0x99,0xd7,0x95,0xd7,0xaa,0x0d,0x0a,0xd7,0xa9,0xd7,0x94,0xd7,0x95,0xd7,0x90,
  0x0d,0x0a,0xd7,0x9e,0xd7,0x99,0x0d,0x0a,0xd7,0x90,0xd7,0x9c,0xd7,0xa3,0x0d,0x0a,
  0xd7,0x90,0xd7,0x9c,0xd7,0x90,0x0d,0x0a,0xd7,0x90,0xd7,0xa3,0x0d,0x0a,0xd7,0x90,
  0xd7,0x97,0xd7,0xa8,0x0d,0x0a,0xd7,0x94,0xd7,0x96,0xd7,0x94,0x0d,0x0a,0xd7,0x90,
  0xd7,0x97,0xd7,0xaa,0x0d,0x0a,0xd7,0x91,0xd7,0x91,0xd7,0x99,0xd7,0xaa,0x0d,0x0a,
  0xd7,0x90,0xd7,0x9c,0xd7,0x94,0x0d,0x0a,0xd7,0x90,0xd7,0xa0,0xd7,0x97,0xd7,0xa0,
  0xd7,0x95,0x0d,0x0a
  };

static std::map<std::string, std::pair<const unsigned char*, unsigned int> > createResourceMap() {
	std::map<std::string, std::pair<const unsigned char*, unsigned int> > m;
	m["stopwords/en"] = std::pair <const unsigned char*, unsigned int>(stopwords_en, sizeof stopwords_en);
	m["stopwords/fra"] = std::pair <const unsigned char*, unsigned int>(stopwords_fra, sizeof stopwords_fra);
	m["stopwords/he"] = std::pair <const unsigned char*, unsigned int>(stopwords_he, sizeof stopwords_he);
	return m;
}

static std::map<std::string, std::pair<const unsigned char*, unsigned int> > resourceMap = createResourceMap();

std::string getResourceAsString(const std::string &name) {
  std::map<std::string, std::pair<const unsigned char*, unsigned int> >::iterator it = resourceMap.find(name);
  if (it != resourceMap.end()) {
    return std::string((const char*)resourceMap[name].first, resourceMap[name].second);
  }
  return "";
}