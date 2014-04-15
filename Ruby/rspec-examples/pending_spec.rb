#
# example for pending()
# (pending() going to be changed in future.)
#

describe "Pending Examples" do
  it "should do something"

  it "pending() with message" do
    pending("some reason")
    true.should be_true
  end

  it "pending () with block" do
    (1 + 1).should == 2
    pending("for obvious reason.") do
      #true.should be_false #deprecated forms.
      true.should be_falsey
    end
    nil.should_not be_true
  end
end
