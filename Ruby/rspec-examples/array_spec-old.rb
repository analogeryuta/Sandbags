#
# array_spec.rb: test code for behaviour of Array
# RSpec extends some object codes (ex, Object#should)
#
describe Array, "when empty" do
  before do
    @empty_array = []
  end

  it "should be empty" do
    @empty_array.should be_empty
  end

  it "should size 0" do
    @empty_array.size.should == 0
  end

  after do
    @empty_array = nil
  end
end

describe Array, "when initialized with object" do
  before do
   # @array = Array.new(3, Hash.new)
    @array = Array.new(3){ Hash.new }
    @array[0][:cat] = "Nuko"
  end

  it "should no affect others" do
    @array.should == [{:cat => "Nuko"}, {}, {}]
  end
end
