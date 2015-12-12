EXAMPLE = 'example'
CUSTOM_TEST_DIR = 'example'

task :default do
	system('make')
	system('./lang < tests/0.good.lang')
end

task :example do
	system("g++ -S -O0 -m32 #{CUSTOM_TEST_DIR}/#{EXAMPLE}.cpp -o #{CUSTOM_TEST_DIR}/#{EXAMPLE}.s")
	system("open #{CUSTOM_TEST_DIR}/#{EXAMPLE}.s")
end


task :csil do
	system('scp -r * mrkohne@csil.cs.ucsb.edu:~/cs160/project6/');
end

task :output do
	system('scp mrkohne@csil.cs.ucsb.edu:~/cs160/project6/my_output.txt .');
end

task :clean do
	system('make clean');
end

task :test do
	system('make clean');
	system('make test');
end