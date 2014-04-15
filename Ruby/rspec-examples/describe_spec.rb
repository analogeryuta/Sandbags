#
# example for describe/before/after behaviours.
#

describe "About describe's behaviours" do
  before(:all) do
    puts "call ... before(:all)"
  end

  before(:each) do
    puts "call ... before(:each)"
  end

  before do
    puts "call ... before"
  end

  it "expect do something" do
    puts "call ... it '' do { ... } end"
  end

  it "expect do something more" do
    puts "call ... it '' do { ... } end"
  end

  after do
    puts "call ... :after"
  end

  after(:each) do
    puts "call ... :after(:each)"
  end

  after(:all) do
    puts "call ... :after(:all)"
  end
end
