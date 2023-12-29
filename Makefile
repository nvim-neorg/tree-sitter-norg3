OUTPUT_FILES = src/grammar.json src/node-types.json

.PHONY: generate
generate: $(OUTPUT_FILES)

$(OUTPUT_FILES): grammar.js src/scanner.cc submodules/tree-sitter
	@echo "Syncing git submodule..."
	git submodule update --init --recursive
	@echo "Building dev-script with Cargo in release mode..."
	cd submodules/tree-sitter && cargo build --release
	@echo "Running tree-sitter binary with given arguments..."
	./submodules/tree-sitter/target/release/tree-sitter generate

.PHONY: test
test:
	tree-sitter test
