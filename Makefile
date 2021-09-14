.PHONY: clean All

All:
	@echo "----------Building project:[ AYED-TP - Debug ]----------"
	@"$(MAKE)" -f  "AYED-TP.mk"
clean:
	@echo "----------Cleaning project:[ AYED-TP - Debug ]----------"
	@"$(MAKE)" -f  "AYED-TP.mk" clean
