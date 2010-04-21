package Class;

sub new{
    my $class = shift;

    # オブジェクトを作成して返す
    my $self = {
        X => 10,
        Y => 100
    };
    return bless $self, $class;
}
#-------------------------------------------------#
package main;

my $obj = new Class;

# インスタンス変数に直接アクセスしている
$obj->{X} = "test A";
$obj->{Y} = "test B";
