#include <math.h>
#include "common.h"

#define NS 640

f64 seg_normal_window_array[2048] = {0,2.3531e-06,9.4124e-06,2.1178e-05,3.7649e-05,5.8826e-05,8.4709e-05,0.0001153,0.00015059,0.00019059,0.00023529,0.0002847,0.00033881,0.00039762,0.00046114,0.00052935,0.00060227,0.00067989,0.00076221,0.00084923,0.00094094,0.0010374,0.0011385,0.0012443,0.0013548,0.00147,0.0015899,0.0017144,0.0018437,0.0019776,0.0021163,0.0022596,0.0024076,0.0025603,0.0027177,0.0028798,0.0030465,0.0032179,0.003394,0.0035748,0.0037602,0.0039503,0.0041451,0.0043446,0.0045487,0.0047575,0.0049709,0.005189,0.0054117,0.0056392,0.0058712,0.0061079,0.0063493,0.0065953,0.006846,0.0071012,0.0073612,0.0076257,0.007895,0.0081688,0.0084473,0.0087303,0.0090181,0.0093104,0.0096074,0.0099089,0.010215,0.010526,0.010841,0.011161,0.011486,0.011815,0.012149,0.012487,0.01283,0.013178,0.01353,0.013887,0.014248,0.014614,0.014984,0.015359,0.015739,0.016123,0.016512,0.016905,0.017303,0.017705,0.018112,0.018523,0.018939,0.01936,0.019785,0.020214,0.020648,0.021087,0.02153,0.021977,0.022429,0.022886,0.023347,0.023812,0.024282,0.024757,0.025236,0.025719,0.026207,0.0267,0.027196,0.027698,0.028203,0.028713,0.029228,0.029747,0.03027,0.030798,0.03133,0.031867,0.032408,0.032954,0.033504,0.034058,0.034617,0.03518,0.035747,0.036319,0.036895,0.037475,0.03806,0.038649,0.039243,0.039841,0.040443,0.04105,0.04166,0.042276,0.042895,0.043519,0.044147,0.044779,0.045416,0.046057,0.046702,0.047352,0.048005,0.048663,0.049326,0.049992,0.050663,0.051338,0.052017,0.0527,0.053388,0.05408,0.054776,0.055476,0.05618,0.056889,0.057601,0.058318,0.059039,0.059765,0.060494,0.061227,0.061965,0.062707,0.063453,0.064202,0.064957,0.065715,0.066477,0.067243,0.068014,0.068788,0.069567,0.070349,0.071136,0.071926,0.072721,0.07352,0.074322,0.075129,0.07594,0.076755,0.077573,0.078396,0.079223,0.080053,0.080888,0.081726,0.082569,0.083415,0.084265,0.085119,0.085977,0.086839,0.087705,0.088575,0.089449,0.090326,0.091208,0.092093,0.092982,0.093875,0.094771,0.095672,0.096576,0.097484,0.098396,0.099312,0.10023,0.10115,0.10208,0.10301,0.10395,0.10488,0.10583,0.10677,0.10772,0.10867,0.10963,0.11059,0.11156,0.11252,0.11349,0.11447,0.11545,0.11643,0.11742,0.11841,0.1194,0.1204,0.1214,0.1224,0.12341,0.12442,0.12543,0.12645,0.12747,0.1285,0.12952,0.13056,0.13159,0.13263,0.13367,0.13472,0.13577,0.13682,0.13788,0.13894,0.14,0.14106,0.14213,0.14321,0.14428,0.14536,0.14645,0.14753,0.14862,0.14972,0.15081,0.15191,0.15301,0.15412,0.15523,0.15634,0.15746,0.15858,0.1597,0.16082,0.16195,0.16309,0.16422,0.16536,0.1665,0.16764,0.16879,0.16994,0.1711,0.17225,0.17341,0.17458,0.17574,0.17691,0.17808,0.17926,0.18044,0.18162,0.1828,0.18399,0.18518,0.18637,0.18757,0.18877,0.18997,0.19118,0.19238,0.19359,0.19481,0.19603,0.19724,0.19847,0.19969,0.20092,0.20215,0.20338,0.20462,0.20586,0.2071,0.20835,0.20959,0.21084,0.2121,0.21335,0.21461,0.21587,0.21713,0.2184,0.21967,0.22094,0.22221,0.22349,0.22477,0.22605,0.22734,0.22862,0.22991,0.23121,0.2325,0.2338,0.2351,0.2364,0.23771,0.23901,0.24032,0.24163,0.24295,0.24427,0.24558,0.24691,0.24823,0.24956,0.25089,0.25222,0.25355,0.25489,0.25622,0.25757,0.25891,0.26025,0.2616,0.26295,0.2643,0.26566,0.26701,0.26837,0.26973,0.27109,0.27246,0.27383,0.27519,0.27657,0.27794,0.27931,0.28069,0.28207,0.28345,0.28484,0.28622,0.28761,0.289,0.29039,0.29179,0.29318,0.29458,0.29598,0.29738,0.29878,0.30019,0.3016,0.303,0.30441,0.30583,0.30724,0.30866,0.31008,0.3115,0.31292,0.31434,0.31577,0.31719,0.31862,0.32005,0.32148,0.32292,0.32435,0.32579,0.32723,0.32867,0.33011,0.33156,0.333,0.33445,0.3359,0.33734,0.3388,0.34025,0.3417,0.34316,0.34462,0.34608,0.34754,0.349,0.35046,0.35192,0.35339,0.35486,0.35633,0.3578,0.35927,0.36074,0.36221,0.36369,0.36517,0.36664,0.36812,0.3696,0.37108,0.37257,0.37405,0.37554,0.37702,0.37851,0.38,0.38149,0.38298,0.38447,0.38596,0.38746,0.38895,0.39045,0.39195,0.39344,0.39494,0.39644,0.39795,0.39945,0.40095,0.40245,0.40396,0.40547,0.40697,0.40848,0.40999,0.4115,0.41301,0.41452,0.41603,0.41754,0.41906,0.42057,0.42209,0.4236,0.42512,0.42663,0.42815,0.42967,0.43119,0.43271,0.43423,0.43575,0.43727,0.43879,0.44032,0.44184,0.44336,0.44489,0.44641,0.44794,0.44947,0.45099,0.45252,0.45405,0.45557,0.4571,0.45863,0.46016,0.46169,0.46322,0.46475,0.46628,0.46781,0.46934,0.47087,0.4724,0.47393,0.47547,0.477,0.47853,0.48006,0.4816,0.48313,0.48466,0.4862,0.48773,0.48926,0.4908,0.49233,0.49386,0.4954,0.49693,0.49847,0.5,0.50153,0.50307,0.5046,0.50614,0.50767,0.5092,0.51074,0.51227,0.5138,0.51534,0.51687,0.5184,0.51994,0.52147,0.523,0.52453,0.52607,0.5276,0.52913,0.53066,0.53219,0.53372,0.53525,0.53678,0.53831,0.53984,0.54137,0.5429,0.54443,0.54595,0.54748,0.54901,0.55053,0.55206,0.55359,0.55511,0.55664,0.55816,0.55968,0.56121,0.56273,0.56425,0.56577,0.56729,0.56881,0.57033,0.57185,0.57337,0.57488,0.5764,0.57791,0.57943,0.58094,0.58246,0.58397,0.58548,0.58699,0.5885,0.59001,0.59152,0.59303,0.59453,0.59604,0.59755,0.59905,0.60055,0.60205,0.60356,0.60506,0.60656,0.60805,0.60955,0.61105,0.61254,0.61404,0.61553,0.61702,0.61851,0.62,0.62149,0.62298,0.62446,0.62595,0.62743,0.62892,0.6304,0.63188,0.63336,0.63483,0.63631,0.63779,0.63926,0.64073,0.6422,0.64367,0.64514,0.64661,0.64808,0.64954,0.651,0.65246,0.65392,0.65538,0.65684,0.6583,0.65975,0.6612,0.66266,0.6641,0.66555,0.667,0.66844,0.66989,0.67133,0.67277,0.67421,0.67565,0.67708,0.67852,0.67995,0.68138,0.68281,0.68423,0.68566,0.68708,0.6885,0.68992,0.69134,0.69276,0.69417,0.69559,0.697,0.6984,0.69981,0.70122,0.70262,0.70402,0.70542,0.70682,0.70821,0.70961,0.711,0.71239,0.71378,0.71516,0.71655,0.71793,0.71931,0.72069,0.72206,0.72343,0.72481,0.72617,0.72754,0.72891,0.73027,0.73163,0.73299,0.73434,0.7357,0.73705,0.7384,0.73975,0.74109,0.74243,0.74378,0.74511,0.74645,0.74778,0.74911,0.75044,0.75177,0.75309,0.75442,0.75573,0.75705,0.75837,0.75968,0.76099,0.76229,0.7636,0.7649,0.7662,0.7675,0.76879,0.77009,0.77138,0.77266,0.77395,0.77523,0.77651,0.77779,0.77906,0.78033,0.7816,0.78287,0.78413,0.78539,0.78665,0.7879,0.78916,0.79041,0.79165,0.7929,0.79414,0.79538,0.79662,0.79785,0.79908,0.80031,0.80153,0.80276,0.80397,0.80519,0.80641,0.80762,0.80882,0.81003,0.81123,0.81243,0.81363,0.81482,0.81601,0.8172,0.81838,0.81956,0.82074,0.82192,0.82309,0.82426,0.82542,0.82659,0.82775,0.8289,0.83006,0.83121,0.83236,0.8335,0.83464,0.83578,0.83691,0.83805,0.83918,0.8403,0.84142,0.84254,0.84366,0.84477,0.84588,0.84699,0.84809,0.84919,0.85028,0.85138,0.85247,0.85355,0.85464,0.85572,0.85679,0.85787,0.85894,0.86,0.86106,0.86212,0.86318,0.86423,0.86528,0.86633,0.86737,0.86841,0.86944,0.87048,0.8715,0.87253,0.87355,0.87457,0.87558,0.87659,0.8776,0.8786,0.8796,0.8806,0.88159,0.88258,0.88357,0.88455,0.88553,0.88651,0.88748,0.88844,0.88941,0.89037,0.89133,0.89228,0.89323,0.89417,0.89512,0.89605,0.89699,0.89792,0.89885,0.89977,0.90069,0.9016,0.90252,0.90342,0.90433,0.90523,0.90613,0.90702,0.90791,0.90879,0.90967,0.91055,0.91142,0.91229,0.91316,0.91402,0.91488,0.91573,0.91659,0.91743,0.91827,0.91911,0.91995,0.92078,0.9216,0.92243,0.92325,0.92406,0.92487,0.92568,0.92648,0.92728,0.92807,0.92886,0.92965,0.93043,0.93121,0.93199,0.93276,0.93352,0.93429,0.93504,0.9358,0.93655,0.93729,0.93804,0.93877,0.93951,0.94024,0.94096,0.94168,0.9424,0.94311,0.94382,0.94452,0.94522,0.94592,0.94661,0.9473,0.94798,0.94866,0.94934,0.95001,0.95067,0.95134,0.95199,0.95265,0.9533,0.95394,0.95458,0.95522,0.95585,0.95648,0.9571,0.95772,0.95834,0.95895,0.95956,0.96016,0.96076,0.96135,0.96194,0.96252,0.96311,0.96368,0.96425,0.96482,0.96538,0.96594,0.9665,0.96705,0.96759,0.96813,0.96867,0.9692,0.96973,0.97025,0.97077,0.97129,0.9718,0.9723,0.9728,0.9733,0.97379,0.97428,0.97476,0.97524,0.97572,0.97619,0.97665,0.97711,0.97757,0.97802,0.97847,0.97891,0.97935,0.97979,0.98022,0.98064,0.98106,0.98148,0.98189,0.98229,0.9827,0.9831,0.98349,0.98388,0.98426,0.98464,0.98502,0.98539,0.98575,0.98611,0.98647,0.98682,0.98717,0.98751,0.98785,0.98818,0.98851,0.98884,0.98916,0.98947,0.98978,0.99009,0.99039,0.99069,0.99098,0.99127,0.99155,0.99183,0.99211,0.99237,0.99264,0.9929,0.99315,0.9934,0.99365,0.99389,0.99413,0.99436,0.99459,0.99481,0.99503,0.99524,0.99545,0.99566,0.99585,0.99605,0.99624,0.99643,0.99661,0.99678,0.99695,0.99712,0.99728,0.99744,0.99759,0.99774,0.99788,0.99802,0.99816,0.99829,0.99841,0.99853,0.99865,0.99876,0.99886,0.99896,0.99906,0.99915,0.99924,0.99932,0.9994,0.99947,0.99954,0.9996,0.99966,0.99972,0.99976,0.99981,0.99985,0.99988,0.99992,0.99994,0.99996,0.99998,0.99999,1,1,1,0.99999,0.99998,0.99996,0.99994,0.99992,0.99988,0.99985,0.99981,0.99976,0.99972,0.99966,0.9996,0.99954,0.99947,0.9994,0.99932,0.99924,0.99915,0.99906,0.99896,0.99886,0.99876,0.99865,0.99853,0.99841,0.99829,0.99816,0.99802,0.99788,0.99774,0.99759,0.99744,0.99728,0.99712,0.99695,0.99678,0.99661,0.99643,0.99624,0.99605,0.99585,0.99566,0.99545,0.99524,0.99503,0.99481,0.99459,0.99436,0.99413,0.99389,0.99365,0.9934,0.99315,0.9929,0.99264,0.99237,0.99211,0.99183,0.99155,0.99127,0.99098,0.99069,0.99039,0.99009,0.98978,0.98947,0.98916,0.98884,0.98851,0.98818,0.98785,0.98751,0.98717,0.98682,0.98647,0.98611,0.98575,0.98539,0.98502,0.98464,0.98426,0.98388,0.98349,0.9831,0.9827,0.98229,0.98189,0.98148,0.98106,0.98064,0.98022,0.97979,0.97935,0.97891,0.97847,0.97802,0.97757,0.97711,0.97665,0.97619,0.97572,0.97524,0.97476,0.97428,0.97379,0.9733,0.9728,0.9723,0.9718,0.97129,0.97077,0.97025,0.96973,0.9692,0.96867,0.96813,0.96759,0.96705,0.9665,0.96594,0.96538,0.96482,0.96425,0.96368,0.96311,0.96252,0.96194,0.96135,0.96076,0.96016,0.95956,0.95895,0.95834,0.95772,0.9571,0.95648,0.95585,0.95522,0.95458,0.95394,0.9533,0.95265,0.95199,0.95134,0.95067,0.95001,0.94934,0.94866,0.94798,0.9473,0.94661,0.94592,0.94522,0.94452,0.94382,0.94311,0.9424,0.94168,0.94096,0.94024,0.93951,0.93877,0.93804,0.93729,0.93655,0.9358,0.93504,0.93429,0.93352,0.93276,0.93199,0.93121,0.93043,0.92965,0.92886,0.92807,0.92728,0.92648,0.92568,0.92487,0.92406,0.92325,0.92243,0.9216,0.92078,0.91995,0.91911,0.91827,0.91743,0.91659,0.91573,0.91488,0.91402,0.91316,0.91229,0.91142,0.91055,0.90967,0.90879,0.90791,0.90702,0.90613,0.90523,0.90433,0.90342,0.90252,0.9016,0.90069,0.89977,0.89885,0.89792,0.89699,0.89605,0.89512,0.89417,0.89323,0.89228,0.89133,0.89037,0.88941,0.88844,0.88748,0.88651,0.88553,0.88455,0.88357,0.88258,0.88159,0.8806,0.8796,0.8786,0.8776,0.87659,0.87558,0.87457,0.87355,0.87253,0.8715,0.87048,0.86944,0.86841,0.86737,0.86633,0.86528,0.86423,0.86318,0.86212,0.86106,0.86,0.85894,0.85787,0.85679,0.85572,0.85464,0.85355,0.85247,0.85138,0.85028,0.84919,0.84809,0.84699,0.84588,0.84477,0.84366,0.84254,0.84142,0.8403,0.83918,0.83805,0.83691,0.83578,0.83464,0.8335,0.83236,0.83121,0.83006,0.8289,0.82775,0.82659,0.82542,0.82426,0.82309,0.82192,0.82074,0.81956,0.81838,0.8172,0.81601,0.81482,0.81363,0.81243,0.81123,0.81003,0.80882,0.80762,0.80641,0.80519,0.80397,0.80276,0.80153,0.80031,0.79908,0.79785,0.79662,0.79538,0.79414,0.7929,0.79165,0.79041,0.78916,0.7879,0.78665,0.78539,0.78413,0.78287,0.7816,0.78033,0.77906,0.77779,0.77651,0.77523,0.77395,0.77266,0.77138,0.77009,0.76879,0.7675,0.7662,0.7649,0.7636,0.76229,0.76099,0.75968,0.75837,0.75705,0.75573,0.75442,0.75309,0.75177,0.75044,0.74911,0.74778,0.74645,0.74511,0.74378,0.74243,0.74109,0.73975,0.7384,0.73705,0.7357,0.73434,0.73299,0.73163,0.73027,0.72891,0.72754,0.72617,0.72481,0.72343,0.72206,0.72069,0.71931,0.71793,0.71655,0.71516,0.71378,0.71239,0.711,0.70961,0.70821,0.70682,0.70542,0.70402,0.70262,0.70122,0.69981,0.6984,0.697,0.69559,0.69417,0.69276,0.69134,0.68992,0.6885,0.68708,0.68566,0.68423,0.68281,0.68138,0.67995,0.67852,0.67708,0.67565,0.67421,0.67277,0.67133,0.66989,0.66844,0.667,0.66555,0.6641,0.66266,0.6612,0.65975,0.6583,0.65684,0.65538,0.65392,0.65246,0.651,0.64954,0.64808,0.64661,0.64514,0.64367,0.6422,0.64073,0.63926,0.63779,0.63631,0.63483,0.63336,0.63188,0.6304,0.62892,0.62743,0.62595,0.62446,0.62298,0.62149,0.62,0.61851,0.61702,0.61553,0.61404,0.61254,0.61105,0.60955,0.60805,0.60656,0.60506,0.60356,0.60205,0.60055,0.59905,0.59755,0.59604,0.59453,0.59303,0.59152,0.59001,0.5885,0.58699,0.58548,0.58397,0.58246,0.58094,0.57943,0.57791,0.5764,0.57488,0.57337,0.57185,0.57033,0.56881,0.56729,0.56577,0.56425,0.56273,0.56121,0.55968,0.55816,0.55664,0.55511,0.55359,0.55206,0.55053,0.54901,0.54748,0.54595,0.54443,0.5429,0.54137,0.53984,0.53831,0.53678,0.53525,0.53372,0.53219,0.53066,0.52913,0.5276,0.52607,0.52453,0.523,0.52147,0.51994,0.5184,0.51687,0.51534,0.5138,0.51227,0.51074,0.5092,0.50767,0.50614,0.5046,0.50307,0.50153,0.5,0.49847,0.49693,0.4954,0.49386,0.49233,0.4908,0.48926,0.48773,0.4862,0.48466,0.48313,0.4816,0.48006,0.47853,0.477,0.47547,0.47393,0.4724,0.47087,0.46934,0.46781,0.46628,0.46475,0.46322,0.46169,0.46016,0.45863,0.4571,0.45557,0.45405,0.45252,0.45099,0.44947,0.44794,0.44641,0.44489,0.44336,0.44184,0.44032,0.43879,0.43727,0.43575,0.43423,0.43271,0.43119,0.42967,0.42815,0.42663,0.42512,0.4236,0.42209,0.42057,0.41906,0.41754,0.41603,0.41452,0.41301,0.4115,0.40999,0.40848,0.40697,0.40547,0.40396,0.40245,0.40095,0.39945,0.39795,0.39644,0.39494,0.39344,0.39195,0.39045,0.38895,0.38746,0.38596,0.38447,0.38298,0.38149,0.38,0.37851,0.37702,0.37554,0.37405,0.37257,0.37108,0.3696,0.36812,0.36664,0.36517,0.36369,0.36221,0.36074,0.35927,0.3578,0.35633,0.35486,0.35339,0.35192,0.35046,0.349,0.34754,0.34608,0.34462,0.34316,0.3417,0.34025,0.3388,0.33734,0.3359,0.33445,0.333,0.33156,0.33011,0.32867,0.32723,0.32579,0.32435,0.32292,0.32148,0.32005,0.31862,0.31719,0.31577,0.31434,0.31292,0.3115,0.31008,0.30866,0.30724,0.30583,0.30441,0.303,0.3016,0.30019,0.29878,0.29738,0.29598,0.29458,0.29318,0.29179,0.29039,0.289,0.28761,0.28622,0.28484,0.28345,0.28207,0.28069,0.27931,0.27794,0.27657,0.27519,0.27383,0.27246,0.27109,0.26973,0.26837,0.26701,0.26566,0.2643,0.26295,0.2616,0.26025,0.25891,0.25757,0.25622,0.25489,0.25355,0.25222,0.25089,0.24956,0.24823,0.24691,0.24558,0.24427,0.24295,0.24163,0.24032,0.23901,0.23771,0.2364,0.2351,0.2338,0.2325,0.23121,0.22991,0.22862,0.22734,0.22605,0.22477,0.22349,0.22221,0.22094,0.21967,0.2184,0.21713,0.21587,0.21461,0.21335,0.2121,0.21084,0.20959,0.20835,0.2071,0.20586,0.20462,0.20338,0.20215,0.20092,0.19969,0.19847,0.19724,0.19603,0.19481,0.19359,0.19238,0.19118,0.18997,0.18877,0.18757,0.18637,0.18518,0.18399,0.1828,0.18162,0.18044,0.17926,0.17808,0.17691,0.17574,0.17458,0.17341,0.17225,0.1711,0.16994,0.16879,0.16764,0.1665,0.16536,0.16422,0.16309,0.16195,0.16082,0.1597,0.15858,0.15746,0.15634,0.15523,0.15412,0.15301,0.15191,0.15081,0.14972,0.14862,0.14753,0.14645,0.14536,0.14428,0.14321,0.14213,0.14106,0.14,0.13894,0.13788,0.13682,0.13577,0.13472,0.13367,0.13263,0.13159,0.13056,0.12952,0.1285,0.12747,0.12645,0.12543,0.12442,0.12341,0.1224,0.1214,0.1204,0.1194,0.11841,0.11742,0.11643,0.11545,0.11447,0.11349,0.11252,0.11156,0.11059,0.10963,0.10867,0.10772,0.10677,0.10583,0.10488,0.10395,0.10301,0.10208,0.10115,0.10023,0.099312,0.098396,0.097484,0.096576,0.095672,0.094771,0.093875,0.092982,0.092093,0.091208,0.090326,0.089449,0.088575,0.087705,0.086839,0.085977,0.085119,0.084265,0.083415,0.082569,0.081726,0.080888,0.080053,0.079223,0.078396,0.077573,0.076755,0.07594,0.075129,0.074322,0.07352,0.072721,0.071926,0.071136,0.070349,0.069567,0.068788,0.068014,0.067243,0.066477,0.065715,0.064957,0.064202,0.063453,0.062707,0.061965,0.061227,0.060494,0.059765,0.059039,0.058318,0.057601,0.056889,0.05618,0.055476,0.054776,0.05408,0.053388,0.0527,0.052017,0.051338,0.050663,0.049992,0.049326,0.048663,0.048005,0.047352,0.046702,0.046057,0.045416,0.044779,0.044147,0.043519,0.042895,0.042276,0.04166,0.04105,0.040443,0.039841,0.039243,0.038649,0.03806,0.037475,0.036895,0.036319,0.035747,0.03518,0.034617,0.034058,0.033504,0.032954,0.032408,0.031867,0.03133,0.030798,0.03027,0.029747,0.029228,0.028713,0.028203,0.027698,0.027196,0.0267,0.026207,0.025719,0.025236,0.024757,0.024282,0.023812,0.023347,0.022886,0.022429,0.021977,0.02153,0.021087,0.020648,0.020214,0.019785,0.01936,0.018939,0.018523,0.018112,0.017705,0.017303,0.016905,0.016512,0.016123,0.015739,0.015359,0.014984,0.014614,0.014248,0.013887,0.01353,0.013178,0.01283,0.012487,0.012149,0.011815,0.011486,0.011161,0.010841,0.010526,0.010215,0.0099089,0.0096074,0.0093104,0.0090181,0.0087303,0.0084473,0.0081688,0.007895,0.0076257,0.0073612,0.0071012,0.006846,0.0065953,0.0063493,0.0061079,0.0058712,0.0056392,0.0054117,0.005189,0.0049709,0.0047575,0.0045487,0.0043446,0.0041451,0.0039503,0.0037602,0.0035748,0.003394,0.0032179,0.0030465,0.0028798,0.0027177,0.0025603,0.0024076,0.0022596,0.0021163,0.0019776,0.0018437,0.0017144,0.0015899,0.00147,0.0013548,0.0012443,0.0011385,0.0010374,0.00094094,0.00084923,0.00076221,0.00067989,0.00060227,0.00052935,0.00046114,0.00039762,0.00033881,0.0002847,0.00023529,0.00019059,0.00015059,0.0001153,8.4709e-05,5.8826e-05,3.7649e-05,2.1178e-05,9.4124e-06,2.3531e-06};
f64 seg_transient_window_array[128] = {0,0.00060227,0.0024076,0.0054117,0.0096074,0.014984,0.02153,0.029228,0.03806,0.048005,0.059039,0.071136,0.084265,0.098396,0.11349,0.12952,0.14645,0.16422,0.1828,0.20215,0.22221,0.24295,0.2643,0.28622,0.30866,0.33156,0.35486,0.37851,0.40245,0.42663,0.45099,0.47547,0.5,0.52453,0.54901,0.57337,0.59755,0.62149,0.64514,0.66844,0.69134,0.71378,0.7357,0.75705,0.77779,0.79785,0.8172,0.83578,0.85355,0.87048,0.88651,0.9016,0.91573,0.92886,0.94096,0.95199,0.96194,0.97077,0.97847,0.98502,0.99039,0.99459,0.99759,0.9994,1,0.9994,0.99759,0.99459,0.99039,0.98502,0.97847,0.97077,0.96194,0.95199,0.94096,0.92886,0.91573,0.9016,0.88651,0.87048,0.85355,0.83578,0.8172,0.79785,0.77779,0.75705,0.7357,0.71378,0.69134,0.66844,0.64514,0.62149,0.59755,0.57337,0.54901,0.52453,0.5,0.47547,0.45099,0.42663,0.40245,0.37851,0.35486,0.33156,0.30866,0.28622,0.2643,0.24295,0.22221,0.20215,0.1828,0.16422,0.14645,0.12952,0.11349,0.098396,0.084265,0.071136,0.059039,0.048005,0.03806,0.029228,0.02153,0.014984,0.0096074,0.0054117,0.0024076,0.00060227};
s32 kb_array[35] = {3,6,9,13,18,23,29,35,43,51,61,72,84,99,115,133,154,178,204,235,270,309,354,405,463,529,603,688,785,895,1019,1161,1322,1505,1712};
s32 IIDi_array[31] = {-50,-45,-40,-35,-30,-25,-22,-19,-16,-13,-10,-8,-6,-4,-2,0,2,4,6,8,10,13,16,19,22,25,30,35,40,45,50};
f64 IPDi_array[8] = {0, M_PI/4, 2*M_PI/4, 3*M_PI/4, M_PI, 5*M_PI/4, 6*M_PI/4, 7*M_PI/4};
f64 ICi_array[8] = {1, 0.937, 0.84118, 0.60092, 0.36764, 0, -0.589, -1};
f64 OPDi_array[8] = {0, M_PI/4, 2*M_PI/4, 3*M_PI/4, M_PI, 5*M_PI/4, 6*M_PI/4, 7*M_PI/4};
f64 hd_array[NS];

void enc_init_generate_decorr_filter (Enc *enc) {
    f64 sum;
    for (s32 n=0; n<NS; ++n) {
        sum = 0.0;
        for (s32 k=0; (k <= NS/2); ++k) {
            sum = sum + cos( (2*M_PI*k*n/enc->Ns) + (2*M_PI*k*(k-1)) );
        }
        enc->hd[n] = sum * 2 / enc->Ns;
    }
}

void ps_init(Enc *enc, s32 _Fs, bool _adpcm_flag) {
    enc->hop_size = 1024;
    enc->td_power_interval = 128;
    enc->td_threshold = 1.3;
    enc->fft_length = 4096;
    enc->B = 34;
    enc->hf_start_band = 18;
    enc->band_0_low_cutoff = 29.7;
    enc->ERB_coeff = 29.2;
    enc->Ns = 640;
    enc->adpcm = _adpcm_flag;
    enc->Fs = _Fs;
    enc->seg_normal_window_length = enc->hop_size*2;
    enc->seg_normal_window_half_length = enc->seg_normal_window_length / 2;
    enc->seg_normal_window = seg_normal_window_array;
    enc->seg_transient_window_length = 128;
    enc->seg_transient_window_half_length = enc->seg_transient_window_length / 2;
    enc->seg_transient_window = seg_transient_window_array;
    enc->td_signal_test_length = enc->seg_normal_window_length + enc->seg_transient_window_half_length + enc->td_power_interval; // 2048 + 64 + 128
    enc->td_scan_zone.crit_start = (enc->seg_normal_window_length + enc->seg_transient_window_length) / 2;
    enc->td_scan_zone.crit_stop = enc->td_scan_zone.crit_start + (enc->seg_normal_window_length / 2);
    enc->td_scan_zone.scan_start = enc->td_scan_zone.crit_start - enc->td_power_interval;
    enc->td_scan_zone.scan_stop = enc->td_scan_zone.crit_stop + enc->td_power_interval;
    enc->kb = kb_array;
    enc->IIDi = IIDi_array;
    enc->IPDi = IPDi_array;
    enc->ICi  = ICi_array;
    enc->OPDi = OPDi_array;
    enc->hd   = hd_array;
    enc_init_generate_decorr_filter(enc);
}