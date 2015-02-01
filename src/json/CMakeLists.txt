set (json
	factory.c
	message.c
	msg-identity.c
	msg-pair.c
	msg-payload.c
)
add_library (json ${json})
target_link_libraries (json ${JSON_LIBRARIES})
