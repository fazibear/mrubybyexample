desc 'Compile project'
task :compile do
  sh "gcc -Iinclude -lmruby -lm src/mruby_main.c -o src/mruby_main"
end

desc 'Run example'
task :run do
  sh "cd src && ./mruby_main"
end

task :default do
  Rake::Task['compile'].execute
  Rake::Task['run'].execute
end
