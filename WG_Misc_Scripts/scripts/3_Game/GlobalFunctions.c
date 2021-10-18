bool HasChance(int chance)
{
    return Math.RandomInt(0, 100) < chance;
}