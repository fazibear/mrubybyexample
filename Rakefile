desc 'Publish to gh-pages'
task :publish do
  sh "git subtree push --prefix docs origin gh-pages"
end

desc 'Compile project'
task :compile do
  sh "gcc -Iinclude -lmruby -lm src/mruby_main.c -o src/mruby_main"
end

task :default => :compile
