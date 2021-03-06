#include <testclass.hpp>
#include <catch.hpp>

SCENARIO ("default"){
	Matrix<int> mat;
	REQUIRE (mat.getRows() == 0);
	REQUIRE (mat.getColumns() == 0);
}

SCENARIO ("constructorTest"){
	Matrix<int> mat(3,3);
	REQUIRE (mat.getRows() == mat.getColumns());
}
SCENARIO("addTest","[!mayfail]"){
	Matrix<int> mat3(3,3);
	std::ifstream("mat3");
	
	Matrix<int> mat4(3,3);
	std::ifstream ("mat4") >> mat4;
	
	Matrix<int> matRes(3,3);
	std::ifstream("addRes") >> matRes;
	
	REQUIRE ((mat3 + mat4) == matRes);
}

SCENARIO("multiTest","[!mayfail]"){
	Matrix<int> mat1(2,3);
	Matrix<int> mat2(3,2);
	
	std::ifstream("mat1") >> mat1;
	std::ifstream("mat2") >> mat2;
	
	Matrix<int> res(2,2);
	std::ifstream("multRes") >> res;
	
	REQUIRE((mat1*mat2) == res);
}

SCENARIO("op="){
	Matrix<int> mat1(2,2);
	Matrix<int> mat2 = mat1;
	REQUIRE (mat1 == mat2);
}

SCENARIO("op=="){
	Matrix<int> mat1(2,2);
	Matrix<int> mat2(2,2);
	
	REQUIRE(mat1 == mat2);
}
SCENARIO("fillMat","[!mayfail]"){
	Matrix<int> mat3(3,3);
	Matrix<int> mat3fill(3,3);
	std::ifstream("mat3") >> mat3;
	mat3fill.fillMatrix("mat3");
	REQUIRE(mat3 == mat3fill);
}
SCENARIO("MULT"){
Matrix<int> mat1(2,2);
mat1.setElement(0,0,1);
mat1.setElement(0,1,1);
mat1.setElement(1,0,1);
mat1.setElement(1,1,1);

Matrix<int> mat2(2,2);
mat2.setElement(0,0,2);
mat2.setElement(0,1,2);
mat2.setElement(1,0,2);
mat2.setElement(1,1,2);

Matrix<int> mat3(2,2);
mat3.setElement(0,0,4);
mat3.setElement(0,1,4);
mat3.setElement(1,0,4);
mat3.setElement(1,1,4);

REQUIRE( (mat1*mat2) == mat3);
}

SCENARIO("add"){
Matrix<int> mat1(2,2);
mat1.setElement(0,0,1);
mat1.setElement(0,1,1);
mat1.setElement(1,0,1);
mat1.setElement(1,1,1);

Matrix<int> mat2(2,2);
mat2.setElement(0,0,2);
mat2.setElement(0,1,2);
mat2.setElement(1,0,2);
mat2.setElement(1,1,2);

Matrix<int> mat3(2,2);
mat3.setElement(0,0,3);
mat3.setElement(0,1,3);
mat3.setElement(1,0,3);
mat3.setElement(1,1,3);

REQUIRE( (mat1+mat2) == mat3);
}