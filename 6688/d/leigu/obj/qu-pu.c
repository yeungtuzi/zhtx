inherit ITEM;

void create()
{
    set_name("笑傲江湖曲",({"xiao ao jiang hu qu", "qu"}));
    set_weight(300);

    if(clonep())
        set_default_object(__FILE__);
    else{
         set("unit","本");
         set("long","正邪本来势不两立,但日月神教长老曲洋与衡山派刘正风以音律相通琴箫相和,结为生死知己.这本曲谱就是他们临死前共创的.据说此曲中琴箫声跌宕起伏,千回百转,述尽江湖不平事,观之者无不感叹不已.然非内力高深且精通音律者不能奏也!\n");
         set("value",500);
         set("material","paper");
         set("skill",([
                "name":"music",
                "exp_required": 10000,
                "sen_cost": 20,
                "base_skill": 50,
                "difficulty": 20,
                "max_skill": 160
         ]));
        }
    setup();
}
