inherit ITEM;

void create()
{
        set_name("青城身法秘芨" , ({ "qingcheng-steps" }) );
        set_weight(600);
        set("unit", "本");
        set("long", "这是青城讲解本门身法的秘芨.\n");
        set("skill", ([
                "name":                 "qingcheng-steps",      
                "exp_required": 30000,       
                "sen_cost":             30,
                "difficulty":   30,
                "base_skill":30,
                "max_skill":    100     
        ]) );
}
      
