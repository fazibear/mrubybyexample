# invoke puts from ruby script
puts 'Hello from mruby!'

# define method in ruby script
def invoke_me
  puts 'Hello from ruby method'
end

# define method with one argunemt and return that argument
def one_arg_method(arg)
  puts "Invoke one_arg_method with: #{arg.inspect}"
  arg
end

# define example class
class SomeClass

  attr_reader :value

  def initialize
    puts 'invoke initialize of SomeClass'
    @value = "some ruby value from initialize"
  end
end
