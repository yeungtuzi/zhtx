///////////////////////////////////////////////////////
//------Newbie Area @ ZHTX2 -------------------------//
//------Made by flyaway -----------------------------//
//------------------------- Jun 2003 ----------------//
///////////////////////////////////////////////////////

// force_book.c 内功心法

inherit ITEM;

void create()
{
        set_name("出村介绍信", ({ "letter" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "封");
                set("long", "这是一封由老村长推荐你出村的介绍信。\n");
                set("value", 5000);
                set("material", "paper");
                set("no_get", 1);
                            set("no_put", 1);
                set("no_give", 1);
        }
}

