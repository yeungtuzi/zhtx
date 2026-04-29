inherit ITEM;

void create()
{
    set_name("溪山行旅图",({"xi shan xing lv tu", "tu"}));
    set_weight(300);

    if(clonep())
        set_default_object(__FILE__);
    else{
         set("unit","本");
         set("long","北宋范中立之作.\n");
         set("value",500);
         set("material","paper");
         set("skill",([
                "name":"drawing",
                "exp_required": 0,
                "sen_cost": 15,
                "base_skill": 30,
                "difficulty": 20,
                "max_skill": 160
         ]));
        }
    setup();
}
