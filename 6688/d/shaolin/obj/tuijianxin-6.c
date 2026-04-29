// tuijianxin-5.c 推荐信 渡-达

inherit ITEM;

void create()
{
        set_name("推荐信",({"tuijian xin6", "xin6", "letter6"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "封");
                set("long", "这是一封渡字辈师尊为你写的推荐信，凭此可以直接向达摩老祖学习武艺。\n");
//              set("no_drop", "这样东西不能离开你。\n");
                set("material", "paper");
        }
}
