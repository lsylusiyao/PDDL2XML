
(define (domain satellite)
  (:requirements :strips :equality :typing :fluents :durative-actions)
	(:types satellite direction instrument mode)
 	(:predicates 
         (on_board ?i - instrument ?s - satellite) //卫星中设备是否在（1/0）
	       (supports ?i - instrument ?m - mode) //模式中设备是否支持（1/0）
	       (pointing ?s - satellite ?d - direction) //方向中卫星指向（用文字）
	       (power_avail ?s - satellite) //卫星电力是否充足（1/0）
	       (power_on ?i - instrument) //设备是否开机（1/0）
	       (calibrated ?i - instrument) //设备是否校正了（1/0）
	       (have_image ?d - direction ?m - mode) //模式中是否在该方向拍照？
	       (calibration_target ?i - instrument ?d - direction)) //这个方向上，这个设备的校正方向？
 
 

  (:functions (slew_time ?a ?b - direction) //方向上转向时间a b
            (calibration_time ?a - instrument ?d - direction) //方向上的设备校正时间
	)

 

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
   :condition (and (over all (on_board ?i ?s)) 
                      (at start (power_avail ?s)))
   :effect (and (at end (power_on ?i))
                (at start (not (calibrated ?i)))
                (at start (not (power_avail ?s)))
           )         
  )

 
  (:durative-action switch_off
   :parameters (?i - instrument ?s - satellite)
   :duration (= ?duration 1)
   :condition (and (over all (on_board ?i ?s))
                      (at start (power_on ?i)) 
                  )
   :effect (and (at start (not (power_on ?i)))
                (at end (power_avail ?s))
           )
  )

  (:durative-action calibrate
   :parameters (?s - satellite ?i - instrument ?d - direction)
   :duration (= ?duration (calibration_time ?i ?d))
   :condition (and (over all (on_board ?i ?s))
		      				 (over all (calibration_target ?i ?d))
                   (at start (pointing ?s ?d))
                   (over all (power_on ?i))
                   (at end (power_on ?i))
              )
   :effect (at end (calibrated ?i)) 
  )


  (:durative-action take_image
   :parameters (?s - satellite ?d - direction ?i - instrument ?m - mode)
   :duration (= ?duration 7)
   :condition (and (over all (calibrated ?i))
                      (over all (on_board ?i ?s))
                      (over all (supports ?i ?m) )
                      (over all (power_on ?i))
                      (over all (pointing ?s ?d))
                      (at end (power_on ?i))
               )
   :effect (at end (have_image ?d ?m))
  )
)

