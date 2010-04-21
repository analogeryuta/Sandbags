package Class;

sub new{
    my $class = shift;

    # オブジェクトを作成して返す
    my $self = {
        X => 10,
        Y => 100,
    };
    return bless $self, $class;
}

sub method1{
    my $self = shift;

    print "$self->{X} : $self->{Y}\n";
}
