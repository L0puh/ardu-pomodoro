if [ ! -d "${BUILDDUR}" ]; then
   mkdir -p build
   cd build
   cmake ..

else 
   cd build
   rm ardu-pomodoro
fi

make
cd ..
./build/ardu-pomodoro
