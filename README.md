# INHA_OSAP_004_Cupcake
## 1st Week (Nov.9 ~ Nov.15)
- **Implementation : empty(), insert(), size()** by. Sungrae Kim
- **Code Review** by. Bong Channavong
- **Google Test** by. Jiyun Kong
- **Preparation for Midterm presentation** by. GyuJun Cho

### Issue 1 : Merge
Regarding Sungrae's pull request, Channavong and Jiyun should have merge after the code review, but both reviewers did merge without completion. Through this, we realized the importance of communication.
<p align="center">
  <img src="https://github.com/jiyun-kong/INHA_OSAP_004_Cupcake/assets/62550230/480f31aa-b79b-4f23-8299-d12d29da6aaa" title="merge issue"/>
</p>

### Issue 2 : Linking
When performing Google Test, the following linking error occurred because linking related to Google Test was not added inside src/tests/CMakefiles.txt.
<p align="Center">
  <img src="https://github.com/jiyun-kong/INHA_OSAP_004_Cupcake/assets/62550230/e0e2bf8d-5e61-433b-a1c9-903ecf806452" title="linking issue"/>
</p><br/>
Error resolved after adding the following code.

`target_link_libraries(unitTest PUBLIC AvlTreeLibrary GTest::GTest GTest::Main)`<br/>
`find_package(GTest REQUIRED)`

## 2nd Week (Nov.16 ~ Nov.20)
- **Implementation : find(), maximum(), minimum()** by. Bong Channavong
- **Code Review** by. Sungrae Kim
- **Google Test, implement main() for Basic functions** by. Jiyun Kong

### Issue 3 : Time Limit
- There's a time limit issue when we test at DomJudge server.
- Probable Cause : Invalid implementation of Minimum(), Maximum() or main() or get_depth() 
- SungRae found that get_depth() is O(n) so replace get_depth() into find()
  
## 3rd Week (Nov.21 ~ Nov.26)
- **Implementation : rank()** by. Bond Channavong
- **Implementation : erase()** by. GyuJun Cho
- **implement main() for Advanced functions, applying Design Pattern** by. Jiyun Long
- **Code Review** by. GyuJun Cho, Jiyun Kong
- **Google Test** by. Sungrae Kim

## 4th Week (Dec.9 ~ Dec.15)

