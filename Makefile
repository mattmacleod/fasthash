default:
	cd rust; cargo build --release
	cp rust/target/release/libfasthash*.a ruby/ext/fasthash/libfasthash.a
	cd ruby/ext/fasthash; ruby extconf.rb; make clean; make
