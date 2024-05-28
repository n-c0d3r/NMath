# NMath
NCoder's Learning Aimed C++ Math Library.

---

## Features
+ Data Types:
  + Base packed data structure templates:
    + **TF_data2<F_element__, F_flag__>**
    + **TF_data3<F_element__, F_flag__>**
    + **TF_data4<F_element__, F_flag__>**
  + Vectors:
    + **F_vector2** = TF_data2<NMATH_DEFAULT_FP_TYPE, F_vector_flag> (`use default element type`)
    + **F_vector2_f32** = TF_data2<f32, F_vector_flag>
    + **F_vector2_i32** = TF_data2<i32, F_vector_flag>
    + **F_vector2_u32** = TF_data2<u32, F_vector_flag>
    + **F_vector3** = TF_data2<NMATH_DEFAULT_FP_TYPE, F_vector_flag> (`use default element type`)
    + **F_vector3_f32** = TF_data2<f32, F_vector_flag>
    + **F_vector3_i32** = TF_data2<i32, F_vector_flag>
    + **F_vector3_u32** = TF_data2<u32, F_vector_flag>
    + **F_vector4** = TF_data2<NMATH_DEFAULT_FP_TYPE, F_vector_flag> (`use default element type`)
    + **F_vector4_f32** = TF_data2<f32, F_vector_flag>
  + Matrices
    + **F_matrix2x2** = TF_data2<NMATH_DEFAULT_FP_TYPE, F_matrix_flag> (`use default element type`)
    + **F_matrix2x2_f32** = TF_data2<f32, F_matrix_flag>
    + **F_matrix3x3** = TF_data2<NMATH_DEFAULT_FP_TYPE, F_matrix_flag> (`use default element type`)
    + **F_matrix3x3_f32** = TF_data2<f32, F_matrix_flag>
    + **F_matrix4x4** = TF_data2<NMATH_DEFAULT_FP_TYPE, F_matrix_flag> (`use default element type`)
    + **F_matrix4x4_f32** = TF_data2<f32, F_matrix_flag>
  + Quaternions:
    + **F_quaternion** = TF_data2<NMATH_DEFAULT_FP_TYPE, F_quaternion_flag> (`use default element type`)
    + **F_quaternion_f32** = TF_data2<f32, F_quaternion_flag>
+ SIMD enabled:
  + Some basic functions support SIMD
  + Currently not fully SIMD but could be in the future
+ Cross-flag packed data functions:
  + There are functions that can be used for various packed data with different flags, such as data4_add(a, b) can be used for both vector4 and quaternion.
  + Highly reusable.
+ Basic functions and operators for scalars, vectors, matrix and quaternions.
+ Some kinds of function for rendering applications:
  + T_projection_matrix<projection_type__, F_element__>(...)

---

## Core Dependencies
+ NCPP

---

## Supported Platforms
  + Windows
  + MacOS
  + Unix Platforms

---

## Supported IDEs and Text Editors (for scripts)
  + Visual Studio
  + Xcode
  + CLion
  + Visual Studio Code

---

## Building
  + **Visual Studio 2022** (Windows):
    + Step 1: Clone [NMath git repository](https://github.com/Abytek/NMath) from GitHub
    + Step 2: Generate Visual Studio 2022 solution by running **scripts/generate_vs2022.bat**
    + Step 3: Navigate to **build/vs2022**
    + Step 4: Open **nmath.sln**
    + Step 5: Set **nmath.samples.hello_nmath** as startup project
    + Step 6: Run and enjoy!
  + **Xcode** (MacOS):
    + Step 1: Clone [NMath git repository](https://github.com/Abytek/NMath) from GitHub
    + Step 2: Generate Xcode solution by running **scripts/generate_xcode.sh**
    + Step 3: Navigate to **build/xcode**
    + Step 4: Open **nmath.xcodeproj**
    + Step 5: Choose **nmath.samples.hello_nmath** for current scheme
    + Step 6: Run and enjoy!
  + **CLion** (Windows, MacOS, Linux):
    + Step 1: Clone [NMath git repository](https://github.com/Abytek/NMath) from GitHub
    + Step 2: Open CLion by running one of these scripts based on your environment (you may need to use chmod +x command first on Linux and MacOS for execute permission):
      + Windows
        + **scripts/python_open_clion.bat**
        + **scripts/python3_open_clion.bat**
      + MacOS, Linux:
        + **scripts/python_open_clion.sh**
        + **scripts/python3_open_clion.sh** 
    + Step 3: At **On Project Wizard**, click "OK" (if you dont see it, dont worry, go to the next step).
    + Step 4: Run and enjoy!
  + **Unix makefiles**:
    + Step 1: Clone [NMath git repository](https://github.com/Abytek/NMath) from GitHub
    + Step 2: Generate makefiles by running **scripts/generate_unix_makefiles.sh**
    + Step 3: execute **scripts/build_unix_makefiles.sh** to build project
    + Step 4: Navigate to **build/unix_makefiles/nmath/samples/hello_nmath**
    + Step 5: Run "nmath.samples.hello_nmath" and enjoy!

---

## License
+ NMath is licensed under the [MIT License](https://github.com/n-c0d3r/NMath/blob/main/LICENSE)
