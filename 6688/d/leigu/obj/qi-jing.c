inherit ITEM;

void create()
{
    set_name("玄玄棋经",({"xuan xuan qi jing", "jing"}));
    set_weight(300);

    if(clonep())
        set_default_object(__FILE__);
    else{
         set("unit","本");
         set("long","这是苏星河编篡的一本围棋谱大全,从传说中的如刘仲甫与山中老妪之呕血谱,王质于烂柯山所观之仙人谱,到当今大国手曹操,过百龄,黄龙士,甚至于东瀛名手>秀策之棋谱,无不收录,古今名谱在此一览无余也!\n");
         set("value",500);
         set("material","paper");
         set("skill",([
                "name":"qi",
                "exp_required": 0,
                "sen_cost": 15,
                "base_skill": 30,
                "difficulty": 20,
                "max_skill": 160
         ]));
        }
    setup();
}
