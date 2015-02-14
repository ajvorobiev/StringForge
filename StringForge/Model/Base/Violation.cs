namespace StringForge.Model
{
    internal interface IViolation
    {
        ViolationLevel Level { get; }

        string Message { get; }
    }
}