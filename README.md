# mruby-snippets

### init mruby
```c
mrb_state *mrb = mrb_open();
```

### load ruby script
```c
FILE *file = fopen("script.rb", "r");
mrb_load_file(mrb, file);
fclose(file);
```
