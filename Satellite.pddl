
(define (domain satellite)
  (:requirements :strips :equality :typing :fluents :durative-actions)
	(:types satellite direction instrument mode)
 	(:predicates 
         (on_board ?i - instrument ?s - satellite) //设备是否在卫星中（1/0）
	       (supports ?i - instrument ?m - mode) //设备是否支持在模式中（1/0）
	       (pointing ?s - satellite ?d - direction) //方向中卫星指向（1/0）
	       (power_avail ?s - satellite) //卫星电力是否充足（1/0）
	       (power_on ?i - instrument) //设备是否开机（1/0）
	       (calibrated ?i - instrument) //设备是否校正了（1/0）
	       (have_image ?d - direction ?m - mode) //模式中是否在该方向拍照？
	       (calibration_target ?i - instrument ?d - direction)) //设备是否校正到这个方向上？
 
 

  (:functions (slew_time ?a ?b - direction) //方向上转向时间a b
            (calibration_time ?a - instrument ?d - direction) //方向上的设备校正时间
	)

 
  //start是一种状态，end是一种结果
  (:durative-action turn_to
   :parameters (?s - satellite ?d_new - direction ?d_prev - direction) //卫星，新方向，以前方向
   :duration (= ?duration (slew_time ?d_prev ?d_new)) //持续时间，时间差
   :condition (and (at start (pointing ?s ?d_prev)) //在开始时指向之前方向则启动
              )
   :effect (and  (at end (pointing ?s ?d_new)) //实现：最终指向新+开始不指向旧？
                 (at start (not (pointing ?s ?d_prev)))
           )
  )

 
  (:durative-action switch_on
   :parameters (?i - instrument ?s - satellite)
   :duration (= ?duration 2)
   :condition (and (over all (on_board ?i ?s))  //要求在卫星上
                      (at start (power_avail ?s))) //有电但未开机
   :effect (and (at end (power_on ?i)) //最后要求开机
                (at start (not (calibrated ?i))) //状态：未校正
                (at start (not (power_avail ?s))) //状态：有电+开机
           )         
  )

 
  (:durative-action switch_off
   :parameters (?i - instrument ?s - satellite)
   :duration (= ?duration 1)
   :condition (and (over all (on_board ?i ?s)) //要求在卫星上
                      (at start (power_on ?i))  //保持开机
                  )
   :effect (and (at start (not (power_on ?i))) //关机
                (at end (power_avail ?s)) //有电但未开机
           )
  )

  (:durative-action calibrate
   :parameters (?s - satellite ?i - instrument ?d - direction) 
   :duration (= ?duration (calibration_time ?i ?d)) //校正中一直保持
   :condition (and (over all (on_board ?i ?s)) //在卫星上
		      				 (over all (calibration_target ?i ?d)) //校准目标存在
                   (at start (pointing ?s ?d)) //开始时目标指向存在
                   (over all (power_on ?i)) //保持开机
                   (at end (power_on ?i))
              )
   :effect (at end (calibrated ?i)) //最终校准完成
  )


  (:durative-action take_image
   :parameters (?s - satellite ?d - direction ?i - instrument ?m - mode)
   :duration (= ?duration 7)
   :condition (and (over all (calibrated ?i)) //全程保持校准
                      (over all (on_board ?i ?s)) //在卫星上
                      (over all (supports ?i ?m) ) //支持？
                      (over all (power_on ?i)) //保持开机
                      (over all (pointing ?s ?d)) //保持指向
                      (at end (power_on ?i)) //最终要开机
               )
   :effect (at end (have_image ?d ?m)) //最终获得图片
  )
)

