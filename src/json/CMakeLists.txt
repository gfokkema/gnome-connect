set (json
	factory.cpp
	message.cpp
	msg-identity.cpp
	msg-pair.cpp
)
add_library (json ${json})
target_link_libraries (json ${JSON_LIBRARIES})
