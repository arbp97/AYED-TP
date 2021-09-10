.PHONY: clean All

All:
	@echo "----------Building project:[ tda-practica2 - Debug ]----------"
	@"$(MAKE)" -f  "tda-practica2.mk"
clean:
	@echo "----------Cleaning project:[ tda-practica2 - Debug ]----------"
	@"$(MAKE)" -f  "tda-practica2.mk" clean
