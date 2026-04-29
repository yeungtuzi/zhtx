//北宋范中立溪山行旅图
//hua.c
inherit ITEM;

void create()
{
        set_name("溪山行旅图", ({ "xishan xinglv tu","picture", "hua" }) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "幅");
                set("value", 1);
                set("long", 
"这是一幅极为陈旧的图画，右上角题着“北宋范中立溪山行旅图”十字，一\n"
"座高山冲天而起，墨韵凝厚，气势雄峻之极。一看便知这幅山水实是精绝之\n"
"作，但见那山森然高耸，虽是纸上的图画，也令人不由自主的兴高山仰止之\n"
"感。\n");
                }
        setup();
}

