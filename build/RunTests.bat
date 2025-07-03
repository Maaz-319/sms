@echo off
echo ================================================================================
echo                    SCHOOL MANAGEMENT SYSTEM - TEST RUNNER
echo ================================================================================
echo.
echo Available Tests:
echo 1. Unit Tests        - Test individual components and classes
echo 2. Integration Tests - Test complete system workflow and integration
echo 3. Both Tests        - Run all tests sequentially
echo 4. Exit
echo.
set /p choice="Select test to run (1-4): "

if "%choice%"=="1" goto UNIT_TEST
if "%choice%"=="2" goto INTEGRATION_TEST
if "%choice%"=="3" goto BOTH_TESTS
if "%choice%"=="4" goto EXIT
echo Invalid choice, please try again.
pause
goto :eof

:UNIT_TEST
echo.
echo Running Unit Tests...
echo ================================================================================
.\UnitTest.exe
echo.
echo Unit Tests Completed!
pause
goto :eof

:INTEGRATION_TEST
echo.
echo Running Integration Tests...
echo ================================================================================
.\IntegrationTest.exe
echo.
echo Integration Tests Completed!
pause
goto :eof

:BOTH_TESTS
echo.
echo Running All Tests...
echo ================================================================================
echo Starting with Unit Tests...
.\UnitTest.exe
echo.
echo ================================================================================
echo Now running Integration Tests...
.\IntegrationTest.exe
echo.
echo ================================================================================
echo All Tests Completed!
pause
goto :eof

:EXIT
echo Goodbye!
