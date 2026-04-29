//呕血谱
//qipu.c
inherit ITEM;

void create()
{
        set_name("呕血谱", ({ "ouxue pu","qipu", "pu" }) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("value", 1);
                set("long", 
"这就是传说中的刘仲甫在骊山遇骊山仙姥，与之对弈的棋谱。\n"
"只见棋谱之中，招招皆是妙手，步步均为好招，实非常人所能。\n");
                }
        setup();
}

