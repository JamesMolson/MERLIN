# Configure this file when creating new user created simulations in order to build them with cmake
# Put all input files into UserSim/data
# Output should be directed to UserSim/outputs or otherwise

macro (thesis_run dir exe_name)
	set(source_files "")
	foreach(arg IN ITEMS ${ARGN})
		list(APPEND source_files ${dir}/${arg})
	endforeach()
	add_executable(${exe_name} ${source_files})

	# To keep the directory structure, we must set the output_name, add a rule to make the directory
	set_target_properties( ${exe_name} PROPERTIES OUTPUT_NAME ${dir}/${exe_name} )
	set_target_properties( ${exe_name} PROPERTIES COMPILE_FLAGS -g )
	add_custom_command(TARGET ${exe_name} PRE_BUILD COMMAND ${CMAKE_COMMAND} -E make_directory ${dir})
	target_link_libraries(${exe_name} merlin)

endmacro (thesis_run)


add_custom_target(DataFiles2 ALL)
add_custom_command(TARGET DataFiles2
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                   ${CMAKE_CURRENT_SOURCE_DIR}/data ${CMAKE_CURRENT_BINARY_DIR}/data)
add_custom_command(TARGET DataFiles2
                   COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_BINARY_DIR}/outputs)

# Add each file to be built as follows:
#thesis_run(directory executable_name cpp_file_name.cpp)
thesis_run(ScatterPlot ScatterPlot scatterplot.cpp)
thesis_run(JawImpact JawImpact JawImpact.cpp)
thesis_run(PlotHELDistn PlotHELDistn PlotHELDistn.cpp)
thesis_run(HL_LossMap HL_LossMap HL_LossMap.cpp)
thesis_run(HELIntegration HELIntegration HELIntegration.cpp)
thesis_run(AV AV AV.cpp)
thesis_run(ClosedOrbit ClosedOrbit ClosedOrbit.cpp)
thesis_run(SymplecticHEL SymplecticHEL SymplecticHEL.cpp)

find_program(MEMORYCHECK_COMMAND NAMES valgrind)
INCLUDE(Dart)


