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
# インスタンス変数へのアクセス用のメソッド
sub modify_obj{
    my ($self, $x, $y) = @_;

    $self->{X} = $x; $self->{Y} = $y;
}
#-------------------------------------------------#
package main;

$obj = new Class;

# アクセスメソッドからインスタンス変数にアクセス
$obj->modify_obj("test A", "test B");
