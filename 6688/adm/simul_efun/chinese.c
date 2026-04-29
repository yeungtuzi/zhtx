
string chinese_number(int i)
{
	return (string)CHINESE_D->chinese_number(i);
}

string to_chinese(string str)
{
	return (string)CHINESE_D->chinese(str);
}

int is_chinese(string str)
{
        // FluffOS: str[0] returns the Unicode codepoint of the first character.
        // CJK Unified (U+4E00-U+9FFF) + CJK Extension A (U+3400-U+4DBF)
        if( strlen(str) < 1 ) return 0;
        int cp = str[0];
        if( cp >= 13312 && cp <= 40959 ) return 1;
        return 0;
}
