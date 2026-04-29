// /obj/book/diannaos.c

inherit ITEM;

void create()
{
        set_name("电脑商情", ({ "computer advertisements", "magazine", "ads" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long","这是一本电脑商情杂志,其实就是本电脑广告.\n");
                set("value", 1000);
                set("material", "paper");
        }
}
